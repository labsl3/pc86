#include "log.h"

struct logger_t
{
     int level;
     FILE *dest;

     struct logger_t *head;
     struct logger_t *prev;
     struct logger_t *next;
};

static struct logger_t *loggers = NULL;

bool log_open (int level, FILE *dest)
{
     /* if the destination is NULL, we can't open the log! */
     if (dest == NULL)
     {
          fprintf (stderr, "[log_open]: Can't open log: destination is nil.");
          return false;
     }

     /* if the log level is inferior to 0, open the log for all levels */
     if (level < 0)
     {
          bool ret = false;

          ret |= log_open (LOG_INFO,     dest);
          ret |= log_open (LOG_WARNING,  dest);
          ret |= log_open (LOG_ERROR,    dest);
          ret |= log_open (LOG_CRITICAL, dest);
          ret |= log_open (LOG_DEBUG,    dest);

          return ret;
     }
     else
     {
          struct logger_t *logger = calloc (1, sizeof (struct logger_t));

          /* we will copy the file descriptor, to prevent a user fclose() on it. */
          int fdcopy = -1;

          /* we can't open the log if there is no memory for it. */
          if (!logger)
          {
               fprintf (stderr, "[log_open]: Can't open log: Can't allocate %lu bytes.", sizeof (struct logger_t));
               return false;
          }

          logger->level = level;

          /* duplicate the destination file descriptor */
          fdcopy = dup (fileno (dest));

          if (fdcopy < 0)
          {
               free (logger);

               fprintf (stderr, "[log_open]: Can't open log: The destination can't be duplicated: %s", strerror (errno));
               return false;
          }

          /* open a stream for the copied file descriptor */
          logger->dest = fdopen (fdcopy, "a+");

          if (logger->dest == NULL)
          {
               free (logger);
               close (fdcopy);

               fprintf (stderr, "[log_open]: Can't open log: The destination can't be duplicated: %s", strerror (errno));
               return false;
          }

          /* add the logger to the loggers list */

          if (loggers == NULL)
          {
               logger->head = logger;
               logger->prev = logger;
               logger->next = logger;

               loggers = logger;
          }
          else
          {
               loggers->prev->next = logger;
               logger->prev = loggers->prev;

               logger->next = loggers;
               loggers->prev = logger;
          }

          return true;
     }
}

void log (int level, char const * const fmt, ...)
{
     struct logger_t *iter = NULL;

     iter = loggers;

     do
     {
          if (iter->level == level)
          {
               va_list args;

               va_start (args, fmt);

               vfprintf (iter->dest, fmt, args);

               va_end (args);
          }

          iter = iter->next;
     }
     while (iter != iter->head);
}
