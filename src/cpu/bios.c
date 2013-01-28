#include "bios.h"
#include "log.h"

bool bios_start (struct cpu_t *cpu)
{
     if (cpu == NULL)
     {
          log (LOG_ERROR, "[bios_start]: Can't run the BIOS if there is no CPU.");
          return false;
     }

     /* TODO */

     return true;
}