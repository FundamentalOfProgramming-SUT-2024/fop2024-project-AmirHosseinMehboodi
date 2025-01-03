#include <ncurses.h>
#include <unistd.h>

int boarder_little();
int boarder_big();
int login_menu();
int game_present();
int checkpassword();

int main() {
  initscr();
  noecho();
  game_present();
  login_menu();
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
  char data[2][100];
  boarder_little();
  mvprintw(11, 60, "Login");
  mvprintw(13, 44, "Username : ");
  mvprintw(15, 44, "Password : ");
  //check if password is right.
  //if wrong
  // if right login
  echo();
  cbreak();
  keypad(stdscr,TRUE);
  move(13,55);
  int num0 =0,num1=0;
  while(1){
    c = getch();
    if (c == KEY_DOWN){
      highlight --;
    }else if(c == KEY_UP){
      highlight ++;
    }else if(c == '\n'){
      if(highlight == 1 || highlight == 0){
        if(data[0] == NULL || data[1] == NULL){
          continue;
        }else{
        //   if(checkpassword() == 1){
        //     //login to game
        //   }else{
        //   mvprintw(17, 44, "Username or Password is wrong!!");
        //   continue;
        //   }
        // }
        }
      }else if(highlight == 3){
        //forgotpassword;
      }else if(highlight == 4){
        //newuser
      }else if(highlight == 5){
        //login as guest
      }
    }
    else{
          if(highlight == 0){
          data[highlight][num0++] = c;
          }
          else if(highlight == 1){
          data[highlight][num1++]= c;
          }
        // if (data[0] != NULL && data[1] != NULL){
        
        }

      if (highlight == 3){
        attron(A_REVERSE);
      mvprintw(19, 44,"Forgot password!");
      attroff(A_REVERSE);
      mvprintw(21, 44, "New user");
      mvprintw(21, 63, "Login as guest");
      }else if(highlight == 4){  
      mvprintw(19, 44,"Forgot password!");
      attron(A_REVERSE);
      mvprintw(21, 44, "New user");
      attroff(A_REVERSE);
      mvprintw(21, 63, "Login as guest");
      }else if(highlight == 5){
      mvprintw(19, 44,"Forgot password!");
      mvprintw(21, 44, "New user");
      attron(A_REVERSE);
      mvprintw(21, 63, "Login as guest");
      attroff(A_REVERSE);
      }
  }
  refresh();
}

int checkpassword(){

}
