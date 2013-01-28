#include "bios.h"
#include "log.h"

struct bios_t *bios_start (struct cpu_t *cpu)
{
     struct bios_t *bios = NULL;

     if (cpu == NULL)
     {
          log (LOG_ERROR, "[bios_start]: Can't run the BIOS if there is no CPU.");
          return NULL;
     }

     bios = calloc (1, sizeof (struct bios_t));

     if (bios == NULL)
     {
          log (LOG_ERROR, "[bios_start]: Can't allocate %lu bytes.", sizeof (struct bios_t));
          return NULL;
     }

     bios->cpu = cpu;

     /* retrieve the 40h segment */
     bios->bda_40h = (struct bda_40h_t *) &(cpu->memory[0x40][0x0]);

     return bios;
}
