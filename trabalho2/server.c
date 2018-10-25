#include "header_files/server-defaults.h"

int main(int argc, char* argv[], char* envp[]){
        char cmd[10];
	int pid;
	SETTINGS s;
	const char *ml = "MEDIT_MAXLINES";
	const char *mc = "MEDIT_MAXCOLUMNS";
	char *mlvar,*mcvar;

	mlvar=getenv(ml);
	mcvar=getenv(mc);

	if (mlvar!=NULL||mlvar!=NULL){
	 	
		s.nlinhas = atoi(mlvar);
		s.ncolunas = atoi(mcvar);
	}
	else{
		s.nlinhas=MEDIT_MAXLINES;
		s.ncolunas=MEDIT_MAXCOLUMNS;
		
	}
	printf("size:%d\n",sizeof(s.matriz[0]));
	//printf("mcvar=%d\n",atoi(mcvar));
	//printf("mlvar=%d\n",atoi(mlvar));
	do{
	//system("clear");
	printf("settings\\load\\save\\free\\statistics\\users\\text\\shutdown\n:");
	scanf("%s", &cmd);
 

	if (strcmp(cmd,"settings") == 0){
		printf("NLinhas:%d\n", MEDIT_MAXLINES);
		printf("NColunas:%d\n", MEDIT_MAXCOLUMNS);
		//printf("Nome BD:");
		//printf("NMAXUSRES:");

      		loadDB("medit.db", "renato");
		
   	}
	else if(strcmp(cmd,"load") == 0){
		//execlp load
	}
	else if (strcmp(cmd,"exit")==0){}
		else printf("comando não conhecido\n");
	}while(strcmp(cmd,"exit")!= 0);
   	printf("\n");
   	return 0;
}
