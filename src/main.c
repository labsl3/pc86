#include <stdlib.h>
#include <stdio.h>

void afficherAide()
{
     printf("pc86 v0.1\n\n"
          "Usage:\n"
          "pc86 --help\n"
          "pc86 [options] fichier\n"
          );
}

int main(int argc, char* argv[])
{
     int i=0;
     const char* nomFichier = NULL;
     
     //Parsing des paramètres
     for(i=1;i<argc;i++)
     {//argv[0] contient le nom du programme et argv[1] le premier paramètre
          if(strcasecmp("--help", argv[i]) == 0)
          {
               afficherAide();
               return EXIT_SUCCESS;
          }
          else if(i == argc-1)
          {//C'est le dernier paramètre, c'est donc le nom du fichier
               nomFichier = argv[i];
          }
          else
          {
               printf("Option invalide : %s\n", argv[i]);
               afficherAide();
               return EXIT_FAILURE;
          }
     }
     if(nomFichier == NULL)
     {
          printf("Nom de fichier requis\n");
          afficherAide();
          return EXIT_FAILURE;
     }
     return EXIT_SUCCESS;
}

