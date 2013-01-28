#ifndef __CPU_H
#define __CPU_H

#include "registers.h"

/*! \brief Structure used to manipulate the CPU */
struct cpu_t
{
     registers_t regs;        /*!< CPU registers */

     int8_t memory[0x100000];  /*!< 1Mb of RAM available */
};

/*!
 * \brief Allocate a new CPU.
 *
 * \return A new CPU object
 */
struct cpu_t *cpu_new (void);

#endif /* __CPU_H */