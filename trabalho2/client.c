#include "header_files/medit-defaults.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char** argv, char** envp){

   int nrow, ncol, posx, posy, oposx, oposy;
   char esp[] = " ";
   int ch,chi;
   int i,j;
   int bloq=0;
   char *aux;

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
   refresh();
   do{
	ch = getch();
	oposy = posy;
        oposx = 2;
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
                    		mvprintw(oposy,oposx+1,"%45s", esp);
                    		bloq=1;
				posx=3;
			}
			else{
				bloq=0;
			}
		
			break;
		//tecla Backspace
		case KEY_BACKSPACE:
			if (posx!=3)
			{
				mvdelch(posy,posx-1);
				posx--;
				attron(COLOR_PAIR(1));
				mvprintw(posy,MEDIT_MAXCOLUMNS+2,"%1s", esp);
				move(posy,posx);
				
			}
			break;
		case KEY_DC:
			if (posx!=MEDIT_MAXCOLUMNS)
			{
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
		refresh();
	}
                    

//   }while(posy!=(nrow-1) || posx!=(ncol-1));
     }while(ch!=27);  
   endwin();

   return 0;
}
