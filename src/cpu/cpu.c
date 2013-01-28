#include <stdlib.h>
#include "cpu.h"
#include "log.h"

struct cpu_t *cpu_new (void)
{
     struct cpu_t *cpu = calloc (1, sizeof (struct cpu_t));

     if (!cpu)
     {
          log (LOG_CRITICAL, "[cpu_new]: Can't allocate %lu bytes", sizeof (struct cpu_t));
          return NULL;
     }

     return cpu;
}
