#include "engine.h"
#include "mpampis.h"
#include "loukas.h"
#include "gem.h"
#include <clocale>

//Εισαγωγή του χάρτη σε ένα vector, αν ανοίγει το αρχείο.

engine::engine(char ** argv){
    string mapline;
    ifstream mapf(argv[1]);
    if(mapf.is_open()){
        while(getline(mapf, mapline)){
            for(int i = 0;i<strlen(mapline.c_str());i++){
                if(mapline[i] == '.'){
                    mapline[i] = ' ';
                }
            }
            map.push_back(mapline);
        }
    }else{
        cout << "Πρόβλημα με το άνοιγμα του αρχείου." << endl;
        exit(EXIT_FAILURE);
    }
    mapf.close();
    width = map.at(0).size();
    height = map.size();
}

engine::~engine(){

}

//Εκτύπωση του χάρτη με χρώματα.

void engine::print(){
    for(int i = 0;i < map.size();i++){
        mvprintw(i, 0, map[i].c_str());
        for(int y = 0;y<map[i].length();y++){
            if(map[i][y] == 'M'){
                attron(COLOR_PAIR(1));
                    mvaddch(i, y, 'M');
                attroff(COLOR_PAIR(1));
            }
            if(map[i][y] == 'L'){
                attron(COLOR_PAIR(2));
                    mvaddch(i, y, 'L');
                attroff(COLOR_PAIR(2));
            }
        }
    }
}

//Έλεγχος της κίνησης.

bool engine::check_move(int c, int y ,int x){
            switch(c){
                case KEY_UP:
                    if(map[y-1][x] == ' ' || map[y-1][x] == '!'){
                        return true;
                    }else
                        return false;
                    break;
                case KEY_DOWN:
                    if(map[y+1][x] == ' ' || map[y+1][x] == '!'){
                        return true;
                    }else
                        return false;
                    break;
                case KEY_LEFT:
                    if(map[y][x-1] == ' ' || map[y][x-1] == '!'){
                        return true;
                    }else
                        return false;
                    break;
                case KEY_RIGHT:
                    if(map[y][x+1] == ' ' || map[y][x+1] == '!'){
                        return true;
                    }else
                        return false;
                    break;
                case 32:
                    return true;
                    break;
                case 27:
                    endwin();
                    exit(EXIT_SUCCESS);
                    return true;
                    break;
                default:
                    return false;
                    break;
        }
}

void engine::start(){
        initscr();
        noecho();
        curs_set(0);
        mousemask(ALL_MOUSE_EVENTS, NULL);

        //Έλεγχος για το αν το τερματικό υποστηρίζει χρώματα.

	    if(has_colors() == FALSE)
	    {	
            endwin();
		    cout << "Το τερματικό δεν υποστηρίζει χρώματα." << endl;
		    exit(EXIT_FAILURE);
	    }
	    start_color();
        init_color(COLOR_YELLOW, 1000, 500, 0);
        init_pair(1, COLOR_YELLOW, 0);
        init_pair(2, COLOR_GREEN, 0);
        mpampis poteridis(map);
        do{
            poteridis.setx(rand() % (width));
            poteridis.sety(rand() % (height));
        }while(map[poteridis.gety()][poteridis.getx()] == '*');
            map[poteridis.gety()][poteridis.getx()] = 'M';
        loukas malfois(map);
        do{
            malfois.setx(rand() % (width));
            malfois.sety(rand() % (height));
        }while(map[malfois.gety()][malfois.getx()] == '*' || map[malfois.gety()][malfois.getx()] == 'M');
            map[malfois.gety()][malfois.getx()] = 'L';
        gem game_gem(map);
        do{
            game_gem.setx(rand() % (width));
            game_gem.sety(rand() % (height));
        }while(map[game_gem.gety()][game_gem.getx()] == '*' || map[game_gem.gety()][game_gem.getx()] == 'M' || map[game_gem.gety()][game_gem.getx()] == 'L');
            map[game_gem.gety()][game_gem.getx()] = '!';
        print();
        refresh();
        keypad(stdscr, true);
        do{
            map[poteridis.gety()][poteridis.getx()] = ' ';
            int c = getch();
            if(check_move(c, poteridis.gety(), poteridis.getx())){
                if(poteridis.get_move(c)){
                    map[poteridis.gety()][poteridis.getx()] = 'M';
                    map[malfois.gety()][malfois.getx()] = ' ';
                    malfois.domove(game_gem.getx(), game_gem.gety());
                    map[malfois.gety()][malfois.getx()] = 'L';

                    //Κίνηση του διαμαντιού σε τυχαίες θέσεις σε "τυχαία" χρονικά διαστήματα.

                    if(game_gem.do_move())
                        map[game_gem.gety()][game_gem.getx()] = '!';
                    print();
                    refresh();
                }
            }
        }while(map[game_gem.gety()][game_gem.getx()] == '!');

        //Έλεγχος και εκτύπωση του ονόματος του νικητή.

        clear();
        if((game_gem.gety() == poteridis.gety() && game_gem.getx() == poteridis.getx()) && (map[game_gem.gety()][game_gem.getx()] == 'L')){
            attron(A_UNDERLINE | A_BOLD | COLOR_PAIR(1));
            mvprintw(1,0,"Ισοπαλία!");
            attroff(COLOR_PAIR(1));   
        }else if(map[game_gem.gety()][game_gem.getx()] == 'M'){
            attron(A_UNDERLINE | A_BOLD | COLOR_PAIR(1));
            mvprintw(1,0,"Νίκησε ο Μπάμπης!");
            attroff(COLOR_PAIR(1));
        }else if(map[game_gem.gety()][game_gem.getx()] == 'L'){
            attron(A_UNDERLINE | A_BOLD | COLOR_PAIR(2));
            mvprintw(1,0,"Νίκησε ο Λουκάς!");
            attroff(COLOR_PAIR(2));
        }
        mvprintw(3,0,"Πάτα οποιοδήποτε πλήκτρο για να συνεχίσεις...");
        getch();
        endwin();
}


