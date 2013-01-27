#ifndef __CPU_H
#define __CPU_H

#include "registers.h"

/*! \brief Structure used to manipulate the CPU */
struct cpu_t
{
     registers_t regs;        /*!< CPU registers */

     int8_t memory[0x10000][0x10000];  /*!< Segmented RAM from 0000h:0000h to FFFFh:FFFFh */
};

/*!
 * \brief Allocate a new CPU.
 *
 * \return A new CPU object
 */
struct cpu_t *cpu_new (void);

#endif /* __CPU_H */
