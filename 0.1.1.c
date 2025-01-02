#include <ncurses.h>
#include <time.h>


int boarder_little();
int boarder_big();
int login_menu();


int main() {
    initscr();  
    cbreak();        
    noecho();
    // game_present;
    // usleep(delay);
    // clear;
    boarder_big();
        login_menu;
        refresh();
    while (1) {
        //mvprintw(1, 1, "Press 'q' to quit or resize the window.");

        int ch = getch();  // Get user input
        if (ch == 'q') {
            break;          // Exit the loop if 'q' is pressed
        } else if (ch == KEY_RESIZE) {
            // Terminal resized; handled in the next iteration
        }
    }

    endwin();  // End ncurses mode
    return 0;
}


int boarder_big(){
    for(int i = 0; i< 188; i++){
        mvprintw(0,i,"#");
        mvprintw(55,i,"#");
    }
    for(int i = 0; i< 56; i++){
        mvprintw(i,0,"#");
        mvprintw(i,187,"#");
    }
}

int boarder_little(){
    for(int i = 59; i< 128; i++){
        mvprintw(14,i,"#");
        mvprintw(42,i,"#");
    }
    for(int i = 14; i< 42; i++){
        mvprintw(i,59,"#");
        mvprintw(i,128,"#");
    }
}

int login_menu(){
        mvprintw(5, 5, "RESID");
    boarder_little();
    mvprintw(16, 89, "Login");
    char name[100];
    scanw("%s",&name);
    refresh();
}
