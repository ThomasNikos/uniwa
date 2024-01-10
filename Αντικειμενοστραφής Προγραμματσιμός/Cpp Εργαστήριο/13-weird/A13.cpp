#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <ncurses.h>


class Scroller {
public:
  char *str;
  void configure();
  void clearScreen();
  void print(int line, int col, int n);
};


void Scroller::configure() {
  initscr();
  raw();
  noecho();
}

void Scroller::clearScreen() {
  clear();
  refresh();
}

void Scroller::print(int line, int col, int n) {
  // if(strlen(str) < n)
    // error
  move(line, col);
  for(int i = 0; i < n; i++)
    addch(str[i]);

  refresh();
}

int main(int argc, char *argv[])
{
  Scroller scrl;


  scrl.clearScreen();

  char *str;
  str = new char[30];
  std::cout << "Enter a string of atleast 20 characters: ";
  std::cin >> *str;


  while(strlen(str) < 20 || str[strlen(str) - 1] == '\n') {
    char *temp;
    scanf("%ms", &temp);

    str = (char*)realloc(str, strlen(str) + strlen(temp) + 1);
    strcat(str, temp);
    free(temp);
  }

  scrl.configure();

  for(int i = 0; true; i++) {
    scrl.str = strndup(&str[i % strlen(str)], 8);
    int len = strlen(scrl.str);
    if(len < 8) {
      strncat(scrl.str, str, 8 - len);
    }
    scrl.print(0, 0, 8);
    sleep(1);
  }

  return 0;
}
