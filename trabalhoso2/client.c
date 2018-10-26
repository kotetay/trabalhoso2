#include "header_files/client-defaults.h"


int main(int argc, char** argv){

    int nrow, ncol, posx=3, posy=2, oposx, oposy;
    char esp[] = " ";
    char buffer[50];
    char op[2],un[10];
    int ch;
    int i,j,k=0;
    int bloq=0;
    LinesEdit li;
   
    if (argc == 3 && sscanf(argv[1],"%s",op)==1 && sscanf(argv[2],"%s",un)==1) {
        if (strcmp(op,"-u") == 0){
            // Processo de comunicação com servidor para verificar se username existe
        }       
    }
    else if (argc == 2 && sscanf(argv[1],"%s",un)==1) {
            // Processo de comunicação com servidor para verificar se username existe        
    }
    else {
        printf("Falta de Argumentos\n");
        return EXIT_FAILURE;
    }

    initscr();
    clear();
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, TRUE);
    //getmaxyx(stdscr, nrow, ncol);
    nrow=17;
    ncol=47;
    init_pair(1, COLOR_RED, COLOR_BLACK);
    mvprintw(0,30,"EDITOR DE TEXTO MEDIT");
    
    for (i=1,j=2;i<=nrow-2;i++,j++){
	mvprintw(j,0,"%d",i);
    }
    
    move(2,3);
    //refresh();
    do{
	ch = getch();
	oposy = posy;
        oposx = posx;
        switch (ch){
            case KEY_UP:
                    posy = (posy>2)?posy-1:posy;
                    break;
            case KEY_DOWN:
                    posy = (posy<(nrow-1))?posy+1:posy;
                    break;
            case KEY_LEFT:
                    posx = (posx>2)?posx-1:posx;
                    break;
            case KEY_RIGHT:
                    posx = (posx<(ncol-1))?posx+1:posx;
                    break;
            //tecla Enter		
            case 10:
                //caso o utilizador ainda não tenha feito nenhum enter
                if(bloq!=1)
                {
                    init_pair(1,COLOR_RED,COLOR_BLUE);
                    attron(COLOR_PAIR(1));
                    mvprintw(oposy,3,"%45s", esp);
                    bloq=1;
                    move(oposy,oposx);
                    
                }
                else{
                    bloq=0;                 
                    //mvprintw(0, 0, "%d", strlen(buffer));
                    for(int i=0;i<strlen(buffer);i++){
                            //for(int j=0;j<posx+3;j++){

                        
			for(int i=0;i<posy+2;i++){
                        	for(int j=0;j<posx+3;j++){
                                    
                                    //li.textEdit[i][j]=buffer[j]; 

                                    //mvprintw(posy+3,posx, "%s", li.textEdit[i][j]);

                                    
                                }
                        
                        }
                        
			posx=3;

                                //li.textEdit[i][j]=&buffer[j]; 
                                mvprintw(oposy posx+i, "%c", buffer[i]);
                                //mvprintw(posy+3,posx, "%c", li.textEdit[i][j]);


                            //}

                    }
                    //posx=3;


		
                }
		
                break;
            //tecla Backspace
            case KEY_BACKSPACE:
                if (posx!=3)
                {
			//apaga um caracter à esquerda
                        mvdelch(posy,posx-1);
                        posx--;
                        attron(COLOR_PAIR(1));
                        mvprintw(posy,MEDIT_MAXCOLUMNS+2,"%1s", esp);
                        move(posy,posx);

                }
                break;
		//tecla delete
            case KEY_DC:
                if (posx!=MEDIT_MAXCOLUMNS)
                {
			//apaga um caracter à direita
                    mvdelch(posy,posx+1);
                    //posx--;
                    attron(COLOR_PAIR(1));
                    mvprintw(posy,MEDIT_MAXCOLUMNS+2,"%1s", esp);
                    move(posy,posx);

                }
                break;
            default:	
		if (bloq==1)
		{
                    if(posx!=MEDIT_MAXCOLUMNS+3)
                    {
			                        

			
/*
                        sprintf(buffer[k],"%c", ch);
                        k++;
*/


			sprintf(&buffer[k],"%c", ch);
                        
                        
                        
                        

                        mvprintw(posy, posx, "%c", ch);
                        //mvprintw(posy+1, posx, "%c", buffer[k]);
                        //mvprintw(posy+2, posx, "%d", k);
                        k++;
                        posx++;
                        

                    }
                    
			
		}
		
		/*tirar dúvida com professor
		if(posx==MEDIT_MAXCOLUMNS-1)
		{
			posy++;
			posx=3;
		}
		else{
		posx++;
		}*/
		break;
        }
        if (ch==KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch == KEY_RIGHT){
            //mvaddch(oposy,oposx,' ');
            move(posy,posx);

            //mvprintw(0,0,"(%d,%d)  ",posy,posx);
            //refresh();
                
	}
                   
    }while(ch!=27);  
     
    
    endwin();

    return 0;
}
