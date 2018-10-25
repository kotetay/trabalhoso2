#include "header_files/server-defaults.h"

int main(int argc, char* argv[], char* envp[]){
        char cmd[10];
	//int pid;
	Matriz m;
        BD b;
        Users u;
        const char *ml = "MEDIT_MAXLINES";
        const char *mc = "MEDIT_MAXCOLUMNS";
        const char *mu = "MEDIT_MAXUSERS";
        
	/*odsfsdafhjdkshfl dsafads f

	sdfdsaf
	fasdasdfsda
	*/
	char *mlvar, *mcvar, *muvar;
        char op[2],op1[10];
        
	mlvar=getenv(ml);
	mcvar=getenv(mc);
        muvar=getenv(mu);
	
        // Variavel de ambiente definida
        if (muvar != NULL){
            if (atoi(muvar) < 15 && atoi(muvar) > 1 ){
                
                u.nMaxUsers = atoi(muvar);
            }
        }
        else {
            // Variavel não definida
            u.nMaxUsers = MEDIT_MAXUSERS;
        }
        
	if (mlvar != NULL && mcvar != NULL){
		m.nlinhas = atoi(mlvar);
		m.ncolunas = atoi(mcvar);
	}else{
            m.nlinhas = MEDIT_MAXLINES;
            m.ncolunas = MEDIT_MAXCOLUMNS;
        }
        
        //printf("argv[1]:%s \n",argv[1]);
        if (argc == 3 && sscanf(argv[1],"%s",op)==1 && sscanf(argv[2],"%s",op1)==1) {
            if (strcmp(op,"-f") == 0){
                //printf("%s", op1);
                strcpy(b.name,op1);
            }
	}
        else {
            strcpy(b.name,"medit.db");
        }
        
	do{
            //system("clear");
            printf("settings\\load\\save\\free\\statistics\\users\\text\\shutdown\n:");
            scanf("%s", &cmd);


            if (strcmp(cmd,"settings") == 0){
                    printf("NLinhas:%d\n", m.nlinhas);
                    printf("NColunas:%d\n", m.ncolunas);
                    printf("NMAXUSERS:%d\n",u.nMaxUsers);
                    printf("BDNAME:%s\n", b.name);
                    printf("%d\n", userCheck(b.name, "renato\n"));

            }
            else if(strcmp(cmd,"load") == 0){
                    //execlp load
            }
            else if(strcmp(cmd,"save") == 0){
                    //execlp load
            }
            else if(strcmp(cmd,"free") == 0){
                    //execlp load
            }
            else if(strcmp(cmd,"statistics") == 0){
                    //execlp load
            }
            else if(strcmp(cmd,"users") == 0){
                    //execlp load
            }
            else if(strcmp(cmd,"text") == 0){
                    //execlp load
            }
            else if (strcmp(cmd,"shutdown")==0) {
                // ......
                exit(EXIT_SUCCESS);
            }
            else printf("comando não conhecido\n");
	}while(strcmp(cmd,"exit")!= 0);
   	printf("\n");
   	return 0;
}
