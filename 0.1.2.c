#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int boarder_little();
int boarder_big();
int login_menu();
int game_present();
int checkpassword();
int NewUser();
int get_random();
int play_game();
int create_rooms();
int generate_wallintins();
struct room{
    int xul;
    int yul;
    int xdr;
    int ydr;
    int doorx[3];
    int doory[3];
};


int main() {
  initscr();
  start_color();
  init_pair(1,COLOR_RED,COLOR_BLACK);
  noecho();
 srand(time(0));
  game_present();
  int result =login_menu();
  if(result != 0){
    //playersmenu;
  }else{
  clear();
  noecho();
  refresh();
  play_game();
    //guestmenu();
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

int game_present() {//naghes
  curs_set(0);
  boarder_big();
  refresh();
  usleep(1500000);
  clear();
  curs_set(1);
}

int login_menu() {//naghes
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
    refresh();
    int num0 = 0, num1 = 0;

    while (1) {
        c = getch();
        if (c == KEY_DOWN) {
            highlight = (highlight + 1) % 5;
        } else if (c == KEY_UP) {
            highlight = (highlight - 1 + 5) % 5;
        } else if (c == '\n') {
            refresh();
            if (highlight == 1) {
                if(checkpassword(data[0],data[1]) != 0){
                    return(checkpassword(data[0],data[1]));
                }else if(checkpassword(data[0],data[1] == 0)){
                    attron(1);
                    mvprintw(17, 44, "Username or Password is wrong!!");
                    attroff(1);
                }
            } else if (highlight == 2) {
                //forgot password
            } else if (highlight == 3) {
                //return NewUser();
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
            noecho();
        } else if (highlight == 3) {
            curs_set(0);
            mvprintw(19, 44, "Forgot password!");
            attron(A_REVERSE);
            mvprintw(21, 44, "New user");
            attroff(A_REVERSE);
            mvprintw(21, 63, "Login as guest");
            noecho();
        } else if (highlight == 4) {
            curs_set(0);
            mvprintw(19, 44, "Forgot password!");
            mvprintw(21, 44, "New user");
            attron(A_REVERSE);
            mvprintw(21, 63, "Login as guest");
            attroff(A_REVERSE);
            noecho();
        }else if(highlight == 0){
            curs_set(1);
            mvprintw(19, 44, "Forgot password!");
            mvprintw(21, 44, "New user");
            mvprintw(21, 63, "Login as guest");
            move(13,55+num0);
            echo();
        }else if(highlight == 1){
            curs_set(1);
            mvprintw(19, 44, "Forgot password!");
            mvprintw(21, 44, "New user");
            mvprintw(21, 63, "Login as guest");
            move(15,55+num1);
            echo();
        }
    refresh();
    }
}


int checkpassword(){//naghes
}


// int NewUser(){//naghes
//     clear();
//     echo();
//     cbreak();
//     keypad(stdscr, TRUE);
//     boarder_little();
//     int highlight = 0;
//     int c;
//     while(1){
//     mvprintw(11, 60, "Login");
//     mvprintw(13, 44, "Username : ");
//     mvprintw(15, 44, "Password : ");
//     mvprintw(17, 44, "Email : ");
//         c = getch();
//         if (c == KEY_DOWN) {
//             highlight = (highlight + 1) % 3;
//         } else if (c == KEY_UP) {
//             highlight = (highlight - 1 + 3) % 3;
//         } else if (c == '\n') {
//             if (highlight == 2) {
//                 if(checkpassword(data[0],data[1]) != 0){
//                     return(checkpassword(data[0],data[1]));
//                 }else if(checkpassword(data[0],data[1] == 0)){
//                     start_color():
//                     attron(COLOR_RED);
//                     mvprintw(17, 44, "Username or Password is wrong!!");
//                     attroff(COLOR_RED);
//                 }
//             }
//         } else {
//             if (highlight == 0) {
//                 mvaddch(13,55+num0, c);
//                 data[highlight][num0++] = c;
//                 data[highlight][num0] = '\0';
//             } else if (highlight == 1) {
//                 mvaddch(15,55+num1, c);
//                 data[highlight][num1++] = c;
//                 data[highlight][num1] = '\0';
//             } else if (highlight == 2) {
//                 mvaddch(17,51+num1, c);
//                 data[highlight][num1++] = c;
//                 data[highlight][num1] = '\0';
//             }
//         }
//     }
    
// }


int play_game(){
    create_rooms();
    while(1){
        int c =getch();
    }
}

int create_rooms(){
    int numroom = get_random(6, 15);
    int rooms[numroom];
    for(int i =0 ; i < numroom;i++){ 
    rooms[i] = get_random(1, 15);
    //printw("%d %d\n",i,rooms[i]);
    //refresh();
        for(int j = i-1; j >= 0; j--){
            if(rooms[i] == rooms[j]){
                i--;
                //printw("ba");
                break;
            }
        }
    }
    // printw("next");
    // refresh();
    int a ,b,x,y;
    struct 
    for(int i = 0; i < numroom; i++){
            move(i,126);
            a = get_random(4,23);
            b = get_random(4, 9);
            int min_x,max_x,min_y,max_y;
            if(rooms[i] %5 == 0){
                min_x =24* ((rooms[i]-1)%5)+2;
                max_x = 24*(rooms[i]%5 +5) +2 - (a + 1);
                if(rooms[i] / 5 == 1){
                    min_y= 2;
                    max_y= 12 - (b + 1);
                }else if(rooms[i] / 5 == 2){
                    min_y = 12;
                    max_y = 22 - (b + 1);
                }else if(rooms[i] / 5 == 3){
                min_y = 22;
                max_y = 32 - (b + 1);
                }
            }else{
                min_x =24* ((rooms[i]-1)%5) +2;
                max_x = 24*(rooms[i]%5) +2 - (a + 1);
                if(rooms[i] / 5 == 0){
                    min_y= 2;
                    max_y= 12 - (b + 1);
                }else if(rooms[i] / 5 == 1){
                    min_y = 12;
                    max_y = 22 - (b + 1);
                }else if(rooms[i] / 5 == 2){
                min_y = 22;
                max_y = 32 - (b + 1);
                }
            }
            x = get_random(min_x,max_x);
            y = get_random(min_y,max_y);
    //printw("%d x=%d y=%d a=%d b=%d room%d\n",i,x,y,a,b,rooms[i]);
    //refresh();
        generate_walls(x,y,a,b);
    }
    // for(int i = 0; i < numroom; i++){
    //     if(rooms[i] == 1){
    //         if (find(2,rooms,numroom) == 1){
    //             if(x)
    //         }else if(find(6,rooms,numroom) ==1){

    //         }else if (find(3,rooms,numroom) == 1){

    //         }else if(find(11,rooms,numroom) == 1){
                
    //         }else if(find(4,rooms,numroom) == 1){

    //         }else if (find(5,rooms,numroom) == 1){

    //         }
    //     } else if(rooms[i] == 2){
    //         // Code for room 2
    //     } else if(rooms[i] == 3){
    //         // Code for room 3
    //     } else if(rooms[i] == 4){
    //         // Code for room 4
    //     } else if(rooms[i] == 5){
    //         // Code for room 5
    //     } else if(rooms[i] == 6){
    //         // Code for room 6
    //     } else if(rooms[i] == 7){
    //         // Code for room 7
    //     } else if(rooms[i] == 8){
    //         // Code for room 8
    //     } else if(rooms[i] == 9){
    //         // Code for room 9
    //     } else if(rooms[i] == 10){
    //         // Code for room 10
    //     } else if(rooms[i] == 11){
    //         // Code for room 11
    //     } else if(rooms[i] == 12){
    //         // Code for room 12
    //     } else if(rooms[i] == 13){
    //         // Code for room 13
    //     } else if(rooms[i] == 14){
    //         // Code for room 14
    //     } else if(rooms[i] == 15){
    //         // Code for room 15
    //     }

    // }
}

int generate_walls(int x, int y, int a, int b){
    //struct room room;
    //room.xul = 
    for(int i = 1;i <= a; i++){      
        mvprintw(y,i + x ,"_");
        mvprintw(y + b + 1,i + x ,"_");
    }
    for (int j = 1;j <= b+1;j++){
        mvprintw(y+j,x , "|");
        mvprintw(y+j,x+a+1 ,"|");
    }
    refresh();
}

generate_door(int x, int y, int a, int b)

int get_random(int min,int max){
    int random = (rand() % (max - min + 1)) + min;
    return random;
}




int find(int k,int rooms, int numroom){
        for(int i = 0; i < numroom;i++){
            if(rooms[i] == k){
                continue;
            }
            if(rooms[i] == k){
                return 1;
            }
        }
    return 0;
}