#include "header_files/client-defaults.h"


int main(int argc, char** argv, char** envp){

    int nrow, ncol, posx, posy, oposx, oposy;
    char esp[] = " ";
    char buffer[2];
    int ch,chi;
    int i,j;
    int bloq=0;
    LinesEdit li;
   


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
    //wborder(WIN *win,'|','|','-','-','+','+','+','+');
    for (i=1,j=2;i<=nrow-2;i++,j++){
	mvprintw(j,0,"%d",i);
    }
    posy = 2;
    posx = 3;
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
                    mvprintw(oposy,oposx,"%45s", esp);
                    bloq=1;
                    move(oposy,oposx);
                    
                }
                else{
                    bloq=0;
                  
			for(int i=0;i<1;i++){
                        	for(int j=0;j<45;j++){
                                    //li.textEdit[i][j]=mvgetch(i+2,j+3);
                                    sprintf(buffer,"%c", mvgetch(i+2,j+3));
                                    li.textEdit[posy-2][posx-3]= buffer; 
                                    //mvprintw(posy,posx, "%s", li.textEdit[posy-2][posx-3]);
                                    //itoa(mvgetch(i+2,j+3),li.textEdit[i][j],1);
/*
                                    if(li.textEdit[i][j]==NULL){
                                        mvprintw(i+2,j+3,"%1s",esp);
                                        break;
                                    }
                                    else{
                                    mvprintw(i+2,j+3,li.textEdit[i][j]);
                                    }
*/
                                }
                        
                        }
			posx=3;
		
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
			                        
			//sprintf(buffer,"%c", ch);
                        //li.textEdit[posy-2][posx-3]= buffer; 
                        //mvprintw(posy,posx, "%s", li.textEdit[posy-2][posx-3]);
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
            //mvaddch(oposy,oposx,' ');
            move(posy,posx);

            //mvprintw(0,0,"(%d,%d)  ",posy,posx);
            //refresh();
                
	}
                   
    }while(ch!=27);  
     
    
    endwin();

    return 0;
}
