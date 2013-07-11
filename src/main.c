#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

void display_help (void)
{
     printf ("pc86 v0.1\n\n"
             "Usage:\n"
             "pc86 --help\n"
             "pc86 [options] <file>\n"
     );
}

int main (int argc, char* argv[])
{
     char const * file_name = NULL;
     
     /* Parameters parsing */
     int optidx = 0;
     int c      = 0;

     struct option const long_options[] =
     {
          { "help", no_argument, 0, 'h' },
          { NULL,   NULL,        0, 0 }
     };

     while ((c = getopt_long (argc, argv, "h", long_options, &optidx)) != -1)
     {
          switch (c)
          {
               case 'h':
                    display_help ();
                    exit (EXIT_SUCCESS);

               /* An invalid option was supplied */
               case '?':
                    display_help ();
                    exit (EXIT_FAILURE);

               default:
                    break;
          }
     }

     if (optind < argc)
     {
          file_name = argv[optind++];
          /* TODO: execute this file */
     }
     else
     {
          fprintf (stderr, "Error: No input file.\n");
          display_help ();

          exit (EXIT_FAILURE);
     }

     return EXIT_SUCCESS;
}

