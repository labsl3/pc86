#ifndef __REGISTERS_H
#define __REGISTERS_H

#include "types.h"

/*! \brief Describe 8086 registers */
struct registers_t
{
     accumulator_t ax;   /*!< Accumulator */
     accumulator_t bx;   /*!< Base */
     accumulator_t cx;   /*!< Counter */
     accumulator_t dx;   /*!< Data */

     int16_t si;         /*!< Source Index */
     int16_t di;         /*!< Destination Index */
     int16_t bp;         /*!< Base Pointer */
     int16_t sp;         /*!< Stack Pointer */

     int16_t es;         /*!< Extra Segment */
     int16_t cs;         /*!< Code Segment */
     int16_t ds;         /*!< Data Segment */
     int16_t fs;         /*!< x86 segment */
     int16_t gs;         /*!< x86 segment */
     int16_t ss;         /*!< Stack Segment */

     int16_t ip;         /*!< Instruction pointer */
};

#endif /* __REGISTERS_H */