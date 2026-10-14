#pragma once
#include "Foititologio.h"
#include <ncurses.h>
#include <string>
#include <vector>

using namespace std;

class UI {
private:
    Foititologio& reg;
    WINDOW* headerWin;
    WINDOW* contentWin;
    WINDOW* statusWin;
    int cRows;
    int cCols;

    void initWindows();
    void destroyWindows();
    void drawHeader();
    void setStatus(const string& msg);
    void clearContent();

    int runMenu(const string& title, const vector<string>& opts);
    string getInput(int row, const string& label);
    int getIntInput(int row, const string& label, int minVal, int maxVal);
    bool getConfirm(const string& question);
    void showMessage(const string& msg, bool isError);
    void waitKey();

    void studentsMenu();
    void listStudents();
    void addStudent();
    void searchStudent();
    void editStudent();
    void removeStudent();
    void enrollStudent();

    void professorsMenu();
    void listProfessors();
    void addProfessor();
    void searchProfessor();
    void editProfessor();
    void removeProfessor();
    void assignCourse();

    void coursesMenu();
    void listCourses();
    void addCourse();
    void searchCourse();
    void editCourse();
    void removeCourse();

    void emailMenu();
    void fileMenu();

public:
    UI(Foititologio& r);
    ~UI();
    void run();
};
