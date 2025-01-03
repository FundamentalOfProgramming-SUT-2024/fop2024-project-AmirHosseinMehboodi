#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int boarder_little();
int boarder_big();
int login_menu();
int game_present();
int checkpassword();
int NewUser();

int main() {
  initscr();
  noecho();
  game_present();
  int result =login_menu();
  if(result != 0){
    playersmenu;
  }else{
    guestmenu;
  }
  while (1) {
    int ch = getch();
    if (ch == 'q') {
      break;
    } else if (ch == KEY_RESIZE) {
    }
  }

  endwin(); 
  return 0;
}

int boarder_big() {
  mvaddch(0, 0, ACS_ULCORNER);
  mvaddch(0, 124, ACS_URCORNER);
  mvaddch(34, 0, ACS_LLCORNER);
  mvaddch(34, 124, ACS_LRCORNER);
  for (int i = 1; i < 124; i++) {
    mvaddch(0, i, ACS_HLINE);
    mvaddch(34, i, ACS_HLINE);
  }
  for (int i = 1; i < 34; i++) {
    mvaddch(i, 0, ACS_VLINE);
    mvaddch(i, 124, ACS_VLINE);
  }
}

int boarder_little() {
  mvaddch(10, 41, ACS_ULCORNER);
  mvaddch(10, 83, ACS_URCORNER);
  mvaddch(24, 41, ACS_LLCORNER);
  mvaddch(24, 83, ACS_LRCORNER);
  for (int i = 42; i < 83; i++) {
    mvaddch(10, i, ACS_HLINE);
    mvaddch(24, i, ACS_HLINE);
  }
  for (int i = 11; i < 24; i++) {
    mvaddch(i, 41, ACS_VLINE);
    mvaddch(i, 83, ACS_VLINE);
  }
}

int game_present() {
  curs_set(0);
  boarder_big();
  refresh();
  usleep(1500000);
  clear();
  curs_set(1);
}

int login_menu() {
    int c;
    int highlight = 0;
    char data[2][100] = {0};
    echo();
    cbreak();
    keypad(stdscr, TRUE);
    boarder_little();
    mvprintw(11, 60, "Login");
    mvprintw(13, 44, "Username : ");
    mvprintw(15, 44, "Password : ");
    mvprintw(19, 44, "Forgot password!");
    mvprintw(21, 44, "New user");
    mvprintw(21, 63, "Login as guest");
    move(13,55);
    int num0 = 0, num1 = 0;

    while (1) {
        c = getch();
        if (c == KEY_DOWN) {
            highlight = (highlight + 1) % 5;
        } else if (c == KEY_UP) {
            highlight = (highlight - 1 + 5) % 5;
        } else if (c == '\n') {
            if (highlight == 1) {
                    if(checkpassword(data[0],data[1]) != 0){
                        return(checkpassword(data[0],data[1]));
                    }else if(checkpassword(data[0],data[1] == 0)){
                        start_color():
                        attron(COLOR_RED);
                        mvprintw(17, 44, "Username or Password is wrong!!");
                        attroff(COLOR_RED);
                    }
            } else if (highlight == 2) {
                //forgot password
            } else if (highlight == 3) {
                return NewUser();
            } else if (highlight == 4) {
                return 0;
            }
        } else {
            if (highlight == 0) {
                mvaddch(13,55+num0, c);
                data[highlight][num0++] = c;
                data[highlight][num0] = '\0';
            } else if (highlight == 1) {
                mvaddch(15,55+num1, c);
                data[highlight][num1++] = c;
                data[highlight][num1] = '\0';
            }
        }


        if (highlight == 2) {
            curs_set(0);
            attron(A_REVERSE);
            mvprintw(19, 44, "Forgot password!");
            attroff(A_REVERSE);
            mvprintw(21, 44, "New user");
            mvprintw(21, 63, "Login as guest");
        } else if (highlight == 3) {
            curs_set(0);
            mvprintw(19, 44, "Forgot password!");
            attron(A_REVERSE);
            mvprintw(21, 44, "New user");
            attroff(A_REVERSE);
            mvprintw(21, 63, "Login as guest");
        } else if (highlight == 4) {
            curs_set(0);
            mvprintw(19, 44, "Forgot password!");
            mvprintw(21, 44, "New user");
            attron(A_REVERSE);
            mvprintw(21, 63, "Login as guest");
            attroff(A_REVERSE);
        }else if(highlight == 0){
            curs_set(1);
            mvprintw(19, 44, "Forgot password!");
            mvprintw(21, 44, "New user");
            mvprintw(21, 63, "Login as guest");
            move(13,55+num0);
        }else if(highlight == 1){
            curs_set(1);
            mvprintw(19, 44, "Forgot password!");
            mvprintw(21, 44, "New user");
            mvprintw(21, 63, "Login as guest");
            move(15,55+num1);
        }
    refresh();
    }
}


int checkpassword(){

}


int NewUser(){
    clear();
    echo();
    cbreak();
    keypad(stdscr, TRUE);
    boarder_little();
    int highlight = 0;
    int c;
    while(1){
    mvprintw(11, 60, "Login");
    mvprintw(13, 44, "Username : ");
    mvprintw(15, 44, "Password : ");
    mvprintw(17, 44, "Email : ")
        c = getch();
        if (c == KEY_DOWN) {
            highlight = (highlight + 1) % 3;
        } else if (c == KEY_UP) {
            highlight = (highlight - 1 + 3) % 3;
        } else if (c == '\n') {
            if (highlight == 2) {
                if(checkpassword(data[0],data[1]) != 0){
                    return(checkpassword(data[0],data[1]));
                }else if(checkpassword(data[0],data[1] == 0)){
                    start_color():
                    attron(COLOR_RED);
                    mvprintw(17, 44, "Username or Password is wrong!!");
                    attroff(COLOR_RED);
                }
            }
        } else {
            if (highlight == 0) {
                mvaddch(13,55+num0, c);
                data[highlight][num0++] = c;
                data[highlight][num0] = '\0';
            } else if (highlight == 1) {
                mvaddch(15,55+num1, c);
                data[highlight][num1++] = c;
                data[highlight][num1] = '\0';
            } else if (highlight == 2) {
                mvaddch(17,51+num1, c);
                data[highlight][num1++] = c;
                data[highlight][num1] = '\0';
            }
        }
    }
    
}