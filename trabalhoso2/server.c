#include "header_files/server-defaults.h"

int main(int argc, char* argv[], char* envp[]){
        char cmd[10];
	//int pid;
	SETTINGS s;
        
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
                
                s.nMaxUsers = atoi(muvar);
            }
        }
        else {
            // Variavel não definida
            s.nMaxUsers = MEDIT_MAXUSERS;
        }
        
	if (mlvar != NULL && mcvar != NULL){
		s.nlinhas = atoi(mlvar);
		s.ncolunas = atoi(mcvar);
	}else{
            s.nlinhas = MEDIT_MAXLINES;
            s.ncolunas = MEDIT_MAXCOLUMNS;
        }
        
        //printf("argv[1]:%s \n",argv[1]);
        if (argc == 3 && sscanf(argv[1],"%s",op)==1 && sscanf(argv[2],"%s",op1)==1) {
            if (strcmp(op,"-f") == 0){
                //printf("%s", op1);
                strcpy(s.BDname,op1);
            }
	}
        else {
            strcpy(s.BDname,"medit.db");
        }
        
	do{
            //system("clear");
            printf("settings\\load\\save\\free\\statistics\\users\\text\\shutdown\n:");
            scanf("%s", &cmd);


            if (strcmp(cmd,"settings") == 0){
                    printf("NLinhas:%d\n", s.nlinhas);
                    printf("NColunas:%d\n", s.ncolunas);
                    printf("NMAXUSERS:%d\n",s.nMaxUsers);
                    printf("BDNAME:%s\n", s.BDname);
                    printf("%d\n", userCheck(s.BDname, "renato\n")); //nome a ser passado pelo pipe

            }
            else if(strcmp(cmd,"load") == 0){
                    //execlp load
            }
            else if(strcmp(cmd,"save") == 0){
                    //execlp save
            }
            else if(strcmp(cmd,"free") == 0){
                    //execlp free
            }
            else if(strcmp(cmd,"statistics") == 0){
                    //execlp statistics
            }
            else if(strcmp(cmd,"users") == 0){
                    //execlp users
            }
            else if(strcmp(cmd,"text") == 0){
                    //execlp text
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
