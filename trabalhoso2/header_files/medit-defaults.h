#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/errno.h>
#include <ncurses.h>
//constantes especificas das linhas
#define MEDIT_MAXLINES 15
#define MEDIT_MAXCOLUMNS 45
//tempo maximo sem editar
#define MEDIT_TIMEOUT 10
