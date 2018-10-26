#include "medit-defaults.h"

#define MEDIT_MAXUSERS 5


// Devolve 0 ou 1 se user existe ou não
int userCheck(char path[], char username[]){

    char *line= NULL;
    size_t len = 0;
    ssize_t read;
    
    FILE *fd;
    if ((fd = fopen(path, "r")) == NULL){
        printf("Erro ao abrir ficheiro\n");
        exit(1);
    }

    while((read = getline(&line,&len, fd)) != -1){
        if((strcmp(line,username)) == 0){ 
            return 1;
        }
    }

    free(line);
    fclose(fd);
    return 0;
    //exit(EXIT_SUCCESS);
};


typedef struct{
   int nlinhas;
   int ncolunas;
   char BDname[10];
   int nMaxUsers;
   int nPipeInt;
   char nPipepri;
}SETTINGS;

typedef struct{
    int pid;
    char fifo[20];
    char user[10];
    int posy; //guardar posicao onde se encontra user, está a ser usada linha
}USER;
