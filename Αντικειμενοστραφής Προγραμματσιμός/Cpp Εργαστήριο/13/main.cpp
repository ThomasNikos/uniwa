#include <iostream>
#include <ncurses.h>

class Message
{
    int N;
    char *message;
    int counter = 0;

public:
    Message(int N);
    void Clear();
    int Input();
    void Print();
};

Message ::Message(int size) : N(size)
{
    if (N < 20)
        throw 10;
    message = new char[N];
}

void Message ::Clear() { wclear(stdscr); }

int Message ::Input()
{
    keypad(stdscr, true);
    int character = wgetch(stdscr);
    if (character == 10)
        return 10;
    return character;
}

void Message ::Print()
{
    int m;
    for (int i = N; i >= 0; i--)
    {
        m = Input();
        if (m == 10)
        {
            i++;
            continue;
        }
        mvwaddch(stdscr, 0, i, (int)m);
        wrefresh(stdscr);
    }
}

int main(int argc, char *argv[])
{
    try
    {
        initscr();
        noecho();
        curs_set(0);

        Message M1(30);
        M1.Print();
        M1.Clear();
        getch();

        endwin();
    }
    catch (int S)
    {
        if (S == 10)
            std::cout << "N should be more than 20" << std::endl;
    }
    return 0;
}