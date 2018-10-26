#include "header_files/client-defaults.h"


int main(int argc, char** argv){

    int nrow, ncol, posx=2, posy=2, oposx, oposy;
    char esp[1] = " ";
    char buffer[45];
    char op[2],un[10];
    int ch;
    int i,j,k=0;
    int bloq=0;
    LinesEdit li;
    memset(&li.textEdit, '\0', sizeof(li.textEdit[0]));
    initscr();
    clear();
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, TRUE);
    nrow=17;
    ncol=47;
    init_pair(1,COLOR_RED,COLOR_BLUE);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
   
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

    
    
    attron(COLOR_PAIR(3));
    mvprintw(0,30,"EDITOR DE TEXTO MEDIT");
    attroff(COLOR_PAIR(3));
    // Desenha no ecra numeraçao de linhas
    for (i=1,j=2;i<=nrow-2;i++,j++){
	mvprintw(j,0,"%d",i);
    }
    
    move(2,2);
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
                    
                    attron(COLOR_PAIR(1));
                    
                    for(int i=0;i<sizeof(li.textEdit[0]);i++){
                        if (li.textEdit[0][i] == '\0'){
                            mvprintw(posy,2+i, " ");
                        }
                        else mvprintw(posy,2+i, "%c", li.textEdit[0][i]);                
                   

                    }
                    //mvprintw(oposy,3,"%45s", esp);
                    bloq=1;
                    move(oposy,oposx);
                    
                    
                }
                else{
                    bloq=0;                 
/*
                    mvprintw(0,0, "%d", strlen(buffer)); 
                    mvprintw(0,0, "%d", sizeof(buffer)); 
*/                  
                    attroff(COLOR_PAIR(1));
                    attron(COLOR_PAIR(2));
                    for(int i=0;i<sizeof(buffer);i++){

                        sprintf(&buffer[i],"%c", mvinch(2,3+i));
                        strcpy(&li.textEdit[0][i], &buffer[i]);                                  
                        mvprintw(posy,2+i, "%c", li.textEdit[0][i]);                
                    }
                    move(oposy,2);
                    attroff(COLOR_PAIR(2));
                    
                    posx=2;
                    //funçao limpa linha apos cursor
                    //clrtoeol();	
                }
		
                break;
            //tecla Backspace
            case KEY_BACKSPACE:
                if (posx!=2 && bloq == 1)
                {
			//apaga um caracter à esquerda
                        mvdelch(posy,posx-1);
                        posx--;
                        attron(COLOR_PAIR(1));
                        mvprintw(posy,MEDIT_MAXCOLUMNS," ");
                        move(posy,posx);

                }
                break;
		//tecla delete
            case KEY_DC:
                if (posx!=MEDIT_MAXCOLUMNS+2 && bloq == 1)
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
                    if(posx!=MEDIT_MAXCOLUMNS+2)
                    {
                        mvprintw(posy, posx, "%c", ch);
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
            move(posy,posx);
       }
                   
    }while(ch!=27);  
     
    
    endwin();

    return 0;
}
