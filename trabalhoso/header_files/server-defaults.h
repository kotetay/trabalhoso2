#include "medit-defaults.h"

#define MEDIT_MAXUSERS 5



void loadDB(char path[], char username[]){

  char *line= NULL;
  size_t len = 0;
  ssize_t read;

  FILE *fd;
  if ((fd = fopen(path, "r")) == NULL){
     printf("Erro ao abrir ficheiro\n");
     exit(1);
  }

  while((read = getline(&line,&len, fd)) != -1){
     if((strcmp("renato","renato")) == 0){
     	printf("tamanho linha: %d\n", read); 
     
     	printf("linha: %s",line);
     }
  }

  free(line);
  fclose(fd);
  exit(EXIT_SUCCESS);
};

int userCheck(char username){
   
}


typedef struct{
   int nlinhas;
   int ncolunas;
   int matriz[0][0];
   char BDname[20];
   int nMaxUsers;
   int nPipeInt;
   char nPipepri;
}SETTINGS;


