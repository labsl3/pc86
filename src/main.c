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
     
     /*Parameters parsing*/
     int c;
     int digit_optind = 0;

     while (1) {
          int this_option_optind = optind ? optind : 1;
          int option_index = 0;
          static struct option long_options[] = {
               {"help",     no_argument, 0,  'h' },
               {0,         0,                 0,  0 }
          };

          c = getopt_long(argc, argv, "h", long_options, &option_index);
          if (c == -1)
               break;

          switch (c) {
               case 'h':
                    display_help ();
                    return EXIT_SUCCESS;

               case '?'://An invalid option was supplied
                    display_help ();
                    return EXIT_FAILURE;
               default:
                    break;
          }
     }

     if (optind < argc) {
          file_name = argv[optind++];
          //TODO:execute this file
     }
     else
     {
          printf ("The file name is required\n");
          display_help ();
          return EXIT_FAILURE;
     }
     return EXIT_SUCCESS;
}

