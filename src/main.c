#include <stdlib.h>
#include <stdio.h>

void display_help()
{
     printf("pc86 v0.1\n\n"
          "Usage:\n"
          "pc86 --help\n"
          "pc86 [options] <file>\n"
          );
}

int main(int argc, char* argv[])
{
     int i=0;
     const char* file_name = NULL;
     
     //Parameters parsing
     for(i=1;i<argc;i++)
     {//argv[0] contains the program name and argv[1] the first parameter
          if(strcasecmp("--help", argv[i]) == 0)
          {
               display_help();
               return EXIT_SUCCESS;
          }
          else if(i == argc-1)
          {//It is the last parameter, i.e. the file name
               file_name = argv[i];
          }
          else
          {
               printf("Invalid option : %s\n", argv[i]);
               display_help();
               return EXIT_FAILURE;
          }
     }
     if(file_name == NULL)
     {
          printf("The file name is required\n");
          display_help();
          return EXIT_FAILURE;
     }
     return EXIT_SUCCESS;
}

