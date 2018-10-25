#include "medit-defaults.h"

//constantes especificas de cliente

#define MEDIT_MAXLINES 15
#define MEDIT_MAXCOLUMNS 45
//tempo maximo sem editar
#define MEDIT_TIMEOUT 10

typedef struct{
   int nrows[MEDIT_MAXLINES];
   int ncols[MEDIT_MAXCOLUMNS];
}EDITOR;

