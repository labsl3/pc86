#ifndef __LOG_H
#define __LOG_H

#include "types.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>

/*! \brief Level of the log message */
enum LogLevel
{
     LOG_INFO = 0,       /*!< Informative */
     LOG_WARNING,        /*!< Warning */
     LOG_ERROR,          /*!< Error */
     LOG_CRITICAL,       /*!< Error, abort needed */
     LOG_DEBUG,          /*!< Debug, should not be show in release mode */

     _LOG_LEVEL
};

/*!
 * \brief Open a log for a defined level.
 *
 * \param level Open the log only for this level (-1 for all)
 * \param dest The destination log (stderr, stdout, other...)
 * \return TRUE on success, FALSE otherwise
 */
bool log_open (int level, FILE *dest);

/*!
 * \brief Log a message
 *
 * \param level Level of the message, see LogLevel
 * \param fmt Format string to log
 * \param ... Parameters for the format string
 */
void log (int level, char const * const fmt, ...);

#endif /* __LOG_H */