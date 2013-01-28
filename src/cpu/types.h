#ifndef __TYPES_H
#define __TYPES_H

#include <stdint.h>
#include <stdbool.h>

/*! \brief Describe an accumulator register */
struct r_accumulator_t
{
     int8_t high;        /*!< High byte of the register */
     int8_t low;         /*!< Low byte of the register */
} __attribute__((packed));

/*! \brief Describe an accumulator register */
typedef union
{
     struct r_accumulator_t byte;  /*!< Access to the byte part of the register */
     int16_t word;                 /*!< Access to the whole register */
} accumulator_t;

/*! \brief Describe the flags register */
struct r_flags_t
{
     uint8_t c : 1; /*!< Carry flag */
     uint8_t   : 1;
     uint8_t p : 1; /*!< Parity flag */
     uint8_t   : 1;
     uint8_t a : 1; /*!< Auxiliary flag */
     uint8_t   : 1;
     uint8_t z : 1; /*!< Zero flag */
     uint8_t s : 1; /*!< Sign flag */
     uint8_t t : 1; /*!< Trap flag */
     uint8_t i : 1; /*!< Interrupt flag */
     uint8_t d : 1; /*!< Direction flag */
     uint8_t o : 1; /*!< Overflow flag */
     uint8_t   : 4;
} __attribute__((packed));

#endif /* __TYPES_H */