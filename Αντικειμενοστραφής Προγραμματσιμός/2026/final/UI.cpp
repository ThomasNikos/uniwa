#include "UI.h"
#include <stdexcept>
#include <sstream>

UI::UI(Foititologio& r)
    : reg(r), headerWin(nullptr), contentWin(nullptr), statusWin(nullptr),
      cRows(0), cCols(0) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

    initWindows();
}

UI::~UI() {
    destroyWindows();
    endwin();
}

void UI::initWindows() {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    headerWin  = newwin(3, cols, 0, 0);
    contentWin = newwin(rows - 5, cols, 3, 0);
    statusWin  = newwin(2, cols, rows - 2, 0);

    cRows = rows - 5 - 2;
    cCols = cols - 2;

    keypad(contentWin, TRUE);
    keypad(statusWin, TRUE);
}

void UI::destroyWindows() {
    if (headerWin)  { delwin(headerWin);  headerWin  = nullptr; }
    if (contentWin) { delwin(contentWin); contentWin = nullptr; }
    if (statusWin)  { delwin(statusWin);  statusWin  = nullptr; }
}

void UI::drawHeader() {
    int cols = getmaxx(headerWin);

    wattron(headerWin, COLOR_PAIR(1) | A_BOLD);
    werase(headerWin);

    string t1 = "ΦΟΙΤΗΤΟΛΟΓΙΟ - Τμήμα Μηχανικών Πληροφορικής & Υπολογιστών - UniWA";
    string t2 = "Νικόλαος Θωμάς  |  ΑΜ: 21390068";

    int x1 = (cols - (int)t1.size()) / 2;
    int x2 = (cols - (int)t2.size()) / 2;
    if (x1 < 1) x1 = 1;
    if (x2 < 1) x2 = 1;

    mvwprintw(headerWin, 0, x1, "%s", t1.c_str());
    mvwprintw(headerWin, 1, x2, "%s", t2.c_str());

    wattroff(headerWin, COLOR_PAIR(1) | A_BOLD);
    wrefresh(headerWin);
}

void UI::setStatus(const string& msg) {
    werase(statusWin);
    mvwprintw(statusWin, 0, 1, "%s", msg.c_str());
    wrefresh(statusWin);
}

void UI::clearContent() {
    werase(contentWin);
    box(contentWin, 0, 0);
    wrefresh(contentWin);
}

int UI::runMenu(const string& title, const vector<string>& opts) {
    int sel = 0;
    int n = (int)opts.size();

    while (true) {
        clearContent();
        wattron(contentWin, A_BOLD);
        mvwprintw(contentWin, 1, 2, "%s", title.c_str());
        wattroff(contentWin, A_BOLD);
        mvwprintw(contentWin, 2, 2, "------------------------------------------------");

        for (int i = 0; i < n && (4 + i) < cRows; i++) {
            if (i == sel) wattron(contentWin, A_REVERSE);
            mvwprintw(contentWin, 4 + i, 4, "  %s  ", opts[i].c_str());
            if (i == sel) wattroff(contentWin, A_REVERSE);
        }

        wrefresh(contentWin);
        setStatus("Πλήκτρα: ↑↓ πλοήγηση | Enter επιλογή | ESC επιστροφή");

        int ch = wgetch(contentWin);
        if (ch == KEY_UP && sel > 0) sel--;
        else if (ch == KEY_DOWN && sel < n - 1) sel++;
        else if (ch == '\n' || ch == '\r' || ch == KEY_ENTER) return sel;
        else if (ch == 27) return -1;
    }
}

string UI::getInput(int row, const string& label) {
    if (row + 1 >= cRows) return "";

    mvwprintw(contentWin, row, 2, "%s", label.c_str());
    mvwprintw(contentWin, row + 1, 4, "> ");
    wclrtoeol(contentWin);
    wrefresh(contentWin);

    echo();
    curs_set(1);
    char buf[512] = {0};
    mvwgetnstr(contentWin, row + 1, 6, buf, 200);
    noecho();
    curs_set(0);

    return string(buf);
}

int UI::getIntInput(int row, const string& label, int minVal, int maxVal) {
    while (true) {
        string s = getInput(row, label);
        if (s.empty()) {
            mvwprintw(contentWin, row + 2, 4, "Η τιμή δεν μπορεί να είναι κενή       ");
            wrefresh(contentWin);
            continue;
        }
        try {
            int v = stoi(s);
            if (v >= minVal && v <= maxVal) return v;
            mvwprintw(contentWin, row + 2, 4, "Εισάγετε τιμή από %d έως %d         ", minVal, maxVal);
            wrefresh(contentWin);
        } catch (...) {
            mvwprintw(contentWin, row + 2, 4, "Παρακαλώ εισάγετε έναν αριθμό         ");
            wrefresh(contentWin);
        }
    }
}

bool UI::getConfirm(const string& question) {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "%s", question.c_str());
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 4, 4, "[Y] Ναι");
    mvwprintw(contentWin, 5, 4, "[N] Όχι");
    wrefresh(contentWin);
    setStatus("Πατήστε Y για επιβεβαίωση ή N για ακύρωση");

    while (true) {
        int ch = wgetch(contentWin);
        if (ch == 'y' || ch == 'Y') return true;
        if (ch == 'n' || ch == 'N' || ch == 27) return false;
    }
}

void UI::showMessage(const string& msg, bool isError) {
    clearContent();
    if (isError) wattron(contentWin, COLOR_PAIR(2) | A_BOLD);
    else         wattron(contentWin, COLOR_PAIR(3) | A_BOLD);
    mvwprintw(contentWin, 3, 3, "%s", msg.c_str());
    if (isError) wattroff(contentWin, COLOR_PAIR(2) | A_BOLD);
    else         wattroff(contentWin, COLOR_PAIR(3) | A_BOLD);
    wrefresh(contentWin);
    waitKey();
}

void UI::waitKey() {
    setStatus("Πατήστε οποιοδήποτε πλήκτρο για συνέχεια...");
    wgetch(contentWin);
}

// ΦΟΙΤΗΤΕΣ

void UI::studentsMenu() {
    vector<string> opts = {
        "Λίστα Φοιτητών",
        "Προσθήκη Φοιτητή",
        "Αναζήτηση Φοιτητή",
        "Επεξεργασία Φοιτητή",
        "Διαγραφή Φοιτητή",
        "Εγγραφή σε Μάθημα",
        "Πίσω"
    };

    while (true) {
        int c = runMenu("Διαχείριση Φοιτητών", opts);
        if (c == -1 || c == 6) return;
        switch (c) {
            case 0: listStudents();   break;
            case 1: addStudent();     break;
            case 2: searchStudent();  break;
            case 3: editStudent();    break;
            case 4: removeStudent();  break;
            case 5: enrollStudent();  break;
        }
    }
}

void UI::listStudents() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Λίστα Φοιτητών");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");

    int row = 4;
    int count = 0;

    for (int i = 0; i < reg.getMemberCount() && row < cRows; i++) {
        Person* p = reg.getMemberAt(i);
        if (p->getType() != "Student") continue;
        Student* s = dynamic_cast<Student*>(p);

        mvwprintw(contentWin, row, 2, "ΑΜ: %-10s | %s | %s | Εξ: %d | Μαθ: %d",
                  s->getCode(),
                  s->getFullName().c_str(),
                  s->getGender() ? "Γυναίκα" : "Άνδρας",
                  s->getSemester(),
                  (int)s->getCourses().size());
        row++;
        count++;
    }

    if (count == 0)
        mvwprintw(contentWin, 4, 2, "Δεν υπάρχουν φοιτητές στο σύστημα.");

    mvwprintw(contentWin, row + 1, 2, "Σύνολο: %d φοιτητής/τριες", count);
    wrefresh(contentWin);
    waitKey();
}

void UI::addStudent() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Προσθήκη Φοιτητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string am     = getInput(4, "Αριθμός Μητρώου (ΑΜ):");
    string name   = getInput(7, "Ονοματεπώνυμο:");
    string gender = getInput(10, "Φύλο (Α=Άνδρας, Γ=Γυναίκα):");
    int    sem    = getIntInput(13, "Εξάμηνο (1-12):", 1, 12);

    if (am.empty() || name.empty()) {
        showMessage("Το ΑΜ και το ονοματεπώνυμο είναι υποχρεωτικά!", true);
        return;
    }

    bool isFemale = (gender == "Γ" || gender == "γ" || gender == "G" || gender == "g");

    try {
        Student* s = new Student(am.c_str(), name, isFemale, (unsigned int)sem);
        reg.addMember(s);
        showMessage("Ο/Η φοιτητής/τρια προστέθηκε επιτυχώς!", false);
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::searchStudent() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Αναζήτηση Φοιτητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string am = getInput(4, "Εισάγετε ΑΜ φοιτητή:");
    if (am.empty()) return;

    Person* p = reg.findMember(am.c_str());
    if (!p || p->getType() != "Student") {
        showMessage("Δεν βρέθηκε φοιτητής με ΑΜ: " + am, true);
        return;
    }

    Student* s = dynamic_cast<Student*>(p);
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Στοιχεία Φοιτητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");

    mvwprintw(contentWin, 4,  2, "ΑΜ:             %s", s->getCode());
    mvwprintw(contentWin, 5,  2, "Ονοματεπώνυμο: %s", s->getFullName().c_str());
    mvwprintw(contentWin, 6,  2, "Φύλο:          %s", s->getGender() ? "Γυναίκα" : "Άνδρας");
    mvwprintw(contentWin, 7,  2, "Εξάμηνο:       %d", s->getSemester());
    mvwprintw(contentWin, 8,  2, "Αριθμός μαθημάτων: %d", (int)s->getCourses().size());

    if (!s->getCourses().empty()) {
        mvwprintw(contentWin, 10, 2, "Εγγεγραμμένα Μαθήματα:");
        int row = 11;
        for (int i = 0; i < (int)s->getCourses().size() && row < cRows; i++) {
            mvwprintw(contentWin, row++, 4, "- [%s] %s",
                      s->getCourses()[i]->getCode().c_str(),
                      s->getCourses()[i]->getDescription().c_str());
        }
    }

    wrefresh(contentWin);
    waitKey();
}

void UI::editStudent() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Επεξεργασία Φοιτητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string am = getInput(4, "Εισάγετε ΑΜ φοιτητή:");
    if (am.empty()) return;

    Person* p = reg.findMember(am.c_str());
    if (!p || p->getType() != "Student") {
        showMessage("Δεν βρέθηκε φοιτητής με ΑΜ: " + am, true);
        return;
    }

    Student* s = dynamic_cast<Student*>(p);

    vector<string> opts = {
        "Αλλαγή Ονόματος",
        "Αλλαγή Εξαμήνου",
        "Αλλαγή Φύλου",
        "Πίσω"
    };

    int choice = runMenu("Επεξεργασία: " + s->getFullName(), opts);
    if (choice == -1 || choice == 3) return;

    try {
        if (choice == 0) {
            clearContent();
            wattron(contentWin, A_BOLD);
            mvwprintw(contentWin, 1, 2, "Αλλαγή Ονόματος");
            wattroff(contentWin, A_BOLD);
            mvwprintw(contentWin, 3, 2, "Τρέχον: %s", s->getFullName().c_str());
            wrefresh(contentWin);
            string newName = getInput(5, "Νέο ονοματεπώνυμο:");
            if (!newName.empty()) {
                s->setFullName(newName);
                showMessage("Το όνομα ενημερώθηκε!", false);
            }
        } else if (choice == 1) {
            clearContent();
            wattron(contentWin, A_BOLD);
            mvwprintw(contentWin, 1, 2, "Αλλαγή Εξαμήνου");
            wattroff(contentWin, A_BOLD);
            mvwprintw(contentWin, 3, 2, "Τρέχον εξάμηνο: %d", s->getSemester());
            wrefresh(contentWin);
            int newSem = getIntInput(5, "Νέο εξάμηνο (1-12):", 1, 12);
            s->setSemester((unsigned int)newSem);
            showMessage("Το εξάμηνο ενημερώθηκε!", false);
        } else if (choice == 2) {
            s->setGender(!s->getGender());
            showMessage(string("Το φύλο άλλαξε σε: ") + (s->getGender() ? "Γυναίκα" : "Άνδρας"), false);
        }
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::removeStudent() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Διαγραφή Φοιτητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string am = getInput(4, "Εισάγετε ΑΜ φοιτητή:");
    if (am.empty()) return;

    Person* p = reg.findMember(am.c_str());
    if (!p || p->getType() != "Student") {
        showMessage("Δεν βρέθηκε φοιτητής με ΑΜ: " + am, true);
        return;
    }

    Student* s = dynamic_cast<Student*>(p);
    if (!getConfirm("Διαγραφή φοιτητή: " + s->getFullName() + ";")) return;

    try {
        reg.removeMember(am.c_str());
        showMessage("Ο/Η φοιτητής/τρια διαγράφηκε!", false);
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::enrollStudent() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Εγγραφή Φοιτητή σε Μάθημα");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string am = getInput(4, "Εισάγετε ΑΜ φοιτητή:");
    if (am.empty()) return;

    Person* p = reg.findMember(am.c_str());
    if (!p || p->getType() != "Student") {
        showMessage("Δεν βρέθηκε φοιτητής με ΑΜ: " + am, true);
        return;
    }

    Student* s = dynamic_cast<Student*>(p);

    if (reg.getCourseCount() == 0) {
        showMessage("Δεν υπάρχουν μαθήματα στο σύστημα.", true);
        return;
    }

    vector<string> courseOpts;
    for (int i = 0; i < reg.getCourseCount(); i++) {
        Course* c = reg.getCourseAt(i);
        courseOpts.push_back("[" + c->getCode() + "] " + c->getDescription());
    }
    courseOpts.push_back("Ακύρωση");

    int choice = runMenu("Επιλογή Μαθήματος για: " + s->getFullName(), courseOpts);
    if (choice == -1 || choice == (int)courseOpts.size() - 1) return;

    Course* c = reg.getCourseAt(choice);

    // Έλεγχος αν είναι ήδη εγγεγραμμένος
    const vector<Course*>& enrolled = s->getCourses();
    for (int i = 0; i < (int)enrolled.size(); i++) {
        if (enrolled[i]->getCode() == c->getCode()) {
            showMessage("Ο φοιτητής είναι ήδη εγγεγραμμένος σε αυτό το μάθημα!", true);
            return;
        }
    }

    s->addCourse(c);
    showMessage("Εγγραφή στο μάθημα [" + c->getCode() + "] " + c->getDescription() + " έγινε!", false);
}

// ΚΑΘΗΓΗΤΕΣ

void UI::professorsMenu() {
    vector<string> opts = {
        "Λίστα Καθηγητών",
        "Προσθήκη Καθηγητή",
        "Αναζήτηση Καθηγητή",
        "Επεξεργασία Καθηγητή",
        "Διαγραφή Καθηγητή",
        "Ανάθεση Μαθήματος",
        "Πίσω"
    };

    while (true) {
        int c = runMenu("Διαχείριση Καθηγητών", opts);
        if (c == -1 || c == 6) return;
        switch (c) {
            case 0: listProfessors();  break;
            case 1: addProfessor();    break;
            case 2: searchProfessor(); break;
            case 3: editProfessor();   break;
            case 4: removeProfessor(); break;
            case 5: assignCourse();    break;
        }
    }
}

void UI::listProfessors() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Λίστα Καθηγητών");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");

    int row = 4;
    int count = 0;

    for (int i = 0; i < reg.getMemberCount() && row < cRows; i++) {
        Person* p = reg.getMemberAt(i);
        if (p->getType() != "Professor") continue;
        Professor* pr = dynamic_cast<Professor*>(p);

        mvwprintw(contentWin, row, 2, "Κωδ: %-8s | %s | %s | Ειδ: %s | Μαθ: %d",
                  pr->getCode(),
                  pr->getFullName().c_str(),
                  pr->getGender() ? "Γυναίκα" : "Άνδρας",
                  pr->getSpecialty().c_str(),
                  (int)pr->getCourses().size());
        row++;
        count++;
    }

    if (count == 0)
        mvwprintw(contentWin, 4, 2, "Δεν υπάρχουν καθηγητές στο σύστημα.");

    mvwprintw(contentWin, row + 1, 2, "Σύνολο: %d καθηγητής/τρια", count);
    wrefresh(contentWin);
    waitKey();
}

void UI::addProfessor() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Προσθήκη Καθηγητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code    = getInput(4, "Κωδικός Καθηγητή:");
    string name    = getInput(7, "Ονοματεπώνυμο:");
    string gender  = getInput(10, "Φύλο (Α=Άνδρας, Γ=Γυναίκα):");
    string spec    = getInput(13, "Ειδικότητα:");

    if (code.empty() || name.empty() || spec.empty()) {
        showMessage("Κωδικός, ονοματεπώνυμο και ειδικότητα είναι υποχρεωτικά!", true);
        return;
    }

    bool isFemale = (gender == "Γ" || gender == "γ" || gender == "G" || gender == "g");

    try {
        Professor* pr = new Professor(code.c_str(), name, isFemale, spec);
        reg.addMember(pr);
        showMessage("Ο/Η καθηγητής/τρια προστέθηκε επιτυχώς!", false);
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::searchProfessor() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Αναζήτηση Καθηγητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Εισάγετε κωδικό καθηγητή:");
    if (code.empty()) return;

    Person* p = reg.findMember(code.c_str());
    if (!p || p->getType() != "Professor") {
        showMessage("Δεν βρέθηκε καθηγητής με κωδικό: " + code, true);
        return;
    }

    Professor* pr = dynamic_cast<Professor*>(p);
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Στοιχεία Καθηγητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");

    mvwprintw(contentWin, 4, 2, "Κωδικός:       %s", pr->getCode());
    mvwprintw(contentWin, 5, 2, "Ονοματεπώνυμο: %s", pr->getFullName().c_str());
    mvwprintw(contentWin, 6, 2, "Φύλο:          %s", pr->getGender() ? "Γυναίκα" : "Άνδρας");
    mvwprintw(contentWin, 7, 2, "Ειδικότητα:    %s", pr->getSpecialty().c_str());
    mvwprintw(contentWin, 8, 2, "Αριθμός μαθημάτων: %d", (int)pr->getCourses().size());

    if (!pr->getCourses().empty()) {
        mvwprintw(contentWin, 10, 2, "Μαθήματα:");
        int row = 11;
        for (int i = 0; i < (int)pr->getCourses().size() && row < cRows; i++) {
            mvwprintw(contentWin, row++, 4, "- [%s] %s",
                      pr->getCourses()[i]->getCode().c_str(),
                      pr->getCourses()[i]->getDescription().c_str());
        }
    }

    wrefresh(contentWin);
    waitKey();
}

void UI::editProfessor() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Επεξεργασία Καθηγητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Εισάγετε κωδικό καθηγητή:");
    if (code.empty()) return;

    Person* p = reg.findMember(code.c_str());
    if (!p || p->getType() != "Professor") {
        showMessage("Δεν βρέθηκε καθηγητής με κωδικό: " + code, true);
        return;
    }

    Professor* pr = dynamic_cast<Professor*>(p);

    vector<string> opts = {
        "Αλλαγή Ονόματος",
        "Αλλαγή Ειδικότητας",
        "Αλλαγή Φύλου",
        "Πίσω"
    };

    int choice = runMenu("Επεξεργασία: " + pr->getFullName(), opts);
    if (choice == -1 || choice == 3) return;

    try {
        if (choice == 0) {
            clearContent();
            wattron(contentWin, A_BOLD);
            mvwprintw(contentWin, 1, 2, "Αλλαγή Ονόματος");
            wattroff(contentWin, A_BOLD);
            mvwprintw(contentWin, 3, 2, "Τρέχον: %s", pr->getFullName().c_str());
            wrefresh(contentWin);
            string newName = getInput(5, "Νέο ονοματεπώνυμο:");
            if (!newName.empty()) {
                pr->setFullName(newName);
                showMessage("Το όνομα ενημερώθηκε!", false);
            }
        } else if (choice == 1) {
            clearContent();
            wattron(contentWin, A_BOLD);
            mvwprintw(contentWin, 1, 2, "Αλλαγή Ειδικότητας");
            wattroff(contentWin, A_BOLD);
            mvwprintw(contentWin, 3, 2, "Τρέχουσα: %s", pr->getSpecialty().c_str());
            wrefresh(contentWin);
            string newSpec = getInput(5, "Νέα ειδικότητα:");
            if (!newSpec.empty()) {
                pr->setSpecialty(newSpec);
                showMessage("Η ειδικότητα ενημερώθηκε!", false);
            }
        } else if (choice == 2) {
            pr->setGender(!pr->getGender());
            showMessage(string("Το φύλο άλλαξε σε: ") + (pr->getGender() ? "Γυναίκα" : "Άνδρας"), false);
        }
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::removeProfessor() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Διαγραφή Καθηγητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Εισάγετε κωδικό καθηγητή:");
    if (code.empty()) return;

    Person* p = reg.findMember(code.c_str());
    if (!p || p->getType() != "Professor") {
        showMessage("Δεν βρέθηκε καθηγητής με κωδικό: " + code, true);
        return;
    }

    Professor* pr = dynamic_cast<Professor*>(p);
    if (!getConfirm("Διαγραφή καθηγητή: " + pr->getFullName() + ";")) return;

    try {
        reg.removeMember(code.c_str());
        showMessage("Ο/Η καθηγητής/τρια διαγράφηκε!", false);
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::assignCourse() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Ανάθεση Μαθήματος σε Καθηγητή");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Εισάγετε κωδικό καθηγητή:");
    if (code.empty()) return;

    Person* p = reg.findMember(code.c_str());
    if (!p || p->getType() != "Professor") {
        showMessage("Δεν βρέθηκε καθηγητής με κωδικό: " + code, true);
        return;
    }

    Professor* pr = dynamic_cast<Professor*>(p);

    if (reg.getCourseCount() == 0) {
        showMessage("Δεν υπάρχουν μαθήματα στο σύστημα.", true);
        return;
    }

    vector<string> courseOpts;
    for (int i = 0; i < reg.getCourseCount(); i++) {
        Course* c = reg.getCourseAt(i);
        courseOpts.push_back("[" + c->getCode() + "] " + c->getDescription());
    }
    courseOpts.push_back("Ακύρωση");

    int choice = runMenu("Επιλογή Μαθήματος για: " + pr->getFullName(), courseOpts);
    if (choice == -1 || choice == (int)courseOpts.size() - 1) return;

    Course* c = reg.getCourseAt(choice);

    const vector<Course*>& prCourses = pr->getCourses();
    for (int i = 0; i < (int)prCourses.size(); i++) {
        if (prCourses[i]->getCode() == c->getCode()) {
            showMessage("Ο καθηγητής διδάσκει ήδη αυτό το μάθημα!", true);
            return;
        }
    }

    pr->addCourse(c);
    showMessage("Το μάθημα [" + c->getCode() + "] ανατέθηκε στον/στην " + pr->getFullName(), false);
}

// ΜΑΘΗΜΑΤΑ

void UI::coursesMenu() {
    vector<string> opts = {
        "Λίστα Μαθημάτων",
        "Προσθήκη Μαθήματος",
        "Αναζήτηση Μαθήματος",
        "Επεξεργασία Μαθήματος",
        "Διαγραφή Μαθήματος",
        "Πίσω"
    };

    while (true) {
        int c = runMenu("Διαχείριση Μαθημάτων", opts);
        if (c == -1 || c == 5) return;
        switch (c) {
            case 0: listCourses();   break;
            case 1: addCourse();     break;
            case 2: searchCourse();  break;
            case 3: editCourse();    break;
            case 4: removeCourse();  break;
        }
    }
}

void UI::listCourses() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Λίστα Μαθημάτων");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");

    int row = 4;
    int count = 0;

    for (int i = 0; i < reg.getCourseCount() && row < cRows; i++) {
        Course* c = reg.getCourseAt(i);
        string resp = (c->getResponsible() != nullptr) ? c->getResponsible()->getFullName() : "-";

        mvwprintw(contentWin, row, 2, "[%s] %s | Εξ: %d | Υπεύθ: %s",
                  c->getCode().c_str(),
                  c->getDescription().c_str(),
                  c->getSemester(),
                  resp.c_str());
        row++;
        count++;
    }

    if (count == 0)
        mvwprintw(contentWin, 4, 2, "Δεν υπάρχουν μαθήματα στο σύστημα.");

    mvwprintw(contentWin, row + 1, 2, "Σύνολο: %d μαθήματα", count);
    wrefresh(contentWin);
    waitKey();
}

void UI::addCourse() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Προσθήκη Μαθήματος");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Κωδικός Μαθήματος (π.χ. CS101):");
    string desc = getInput(7, "Περιγραφή:");
    int    sem  = getIntInput(10, "Εξάμηνο διδασκαλίας (1-12):", 1, 12);

    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Υπεύθυνος Καθηγητής (προαιρετικό)");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string respCode = getInput(4, "Κωδικός υπεύθυνου καθηγητή (Enter για παράλειψη):");

    if (code.empty() || desc.empty()) {
        showMessage("Κωδικός και περιγραφή είναι υποχρεωτικά!", true);
        return;
    }

    Professor* resp = nullptr;
    if (!respCode.empty()) {
        Person* p = reg.findMember(respCode.c_str());
        if (p && p->getType() == "Professor")
            resp = dynamic_cast<Professor*>(p);
        else if (!respCode.empty())
            showMessage("Προσοχή: Δεν βρέθηκε καθηγητής με κωδικό " + respCode + ". Το μάθημα θα προστεθεί χωρίς υπεύθυνο.", false);
    }

    try {
        Course* c = new Course(code, desc, (unsigned int)sem, resp);
        reg.addCourse(c);
        if (resp != nullptr) resp->addCourse(c);
        showMessage("Το μάθημα [" + code + "] προστέθηκε επιτυχώς!", false);
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::searchCourse() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Αναζήτηση Μαθήματος");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Εισάγετε κωδικό μαθήματος:");
    if (code.empty()) return;

    Course* c = reg.findCourse(code);
    if (!c) {
        showMessage("Δεν βρέθηκε μάθημα με κωδικό: " + code, true);
        return;
    }

    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Στοιχεία Μαθήματος");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");

    mvwprintw(contentWin, 4, 2, "Κωδικός:     %s", c->getCode().c_str());
    mvwprintw(contentWin, 5, 2, "Περιγραφή:   %s", c->getDescription().c_str());
    mvwprintw(contentWin, 6, 2, "Εξάμηνο:     %d", c->getSemester());

    if (c->getResponsible() != nullptr)
        mvwprintw(contentWin, 7, 2, "Υπεύθυνος:   %s (%s)",
                  c->getResponsible()->getFullName().c_str(),
                  c->getResponsible()->getCode());
    else
        mvwprintw(contentWin, 7, 2, "Υπεύθυνος:   -");

    // Εμφάνιση εγγεγραμμένων φοιτητών
    int row = 9;
    int stCount = 0;
    mvwprintw(contentWin, row++, 2, "Εγγεγραμμένοι Φοιτητές:");
    for (int i = 0; i < reg.getMemberCount() && row < cRows; i++) {
        Person* p = reg.getMemberAt(i);
        if (p->getType() != "Student") continue;
        Student* s = dynamic_cast<Student*>(p);
        const vector<Course*>& sc = s->getCourses();
        for (int j = 0; j < (int)sc.size(); j++) {
            if (sc[j]->getCode() == c->getCode()) {
                mvwprintw(contentWin, row++, 4, "- %s (%s)", s->getFullName().c_str(), s->getCode());
                stCount++;
                break;
            }
        }
    }
    if (stCount == 0)
        mvwprintw(contentWin, row, 4, "(κανένας)");

    wrefresh(contentWin);
    waitKey();
}

void UI::editCourse() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Επεξεργασία Μαθήματος");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Εισάγετε κωδικό μαθήματος:");
    if (code.empty()) return;

    Course* c = reg.findCourse(code);
    if (!c) {
        showMessage("Δεν βρέθηκε μάθημα με κωδικό: " + code, true);
        return;
    }

    vector<string> opts = {
        "Αλλαγή Περιγραφής",
        "Αλλαγή Εξαμήνου",
        "Αλλαγή Υπεύθυνου Καθηγητή",
        "Πίσω"
    };

    int choice = runMenu("Επεξεργασία: [" + c->getCode() + "] " + c->getDescription(), opts);
    if (choice == -1 || choice == 3) return;

    try {
        if (choice == 0) {
            clearContent();
            mvwprintw(contentWin, 3, 2, "Τρέχουσα περιγραφή: %s", c->getDescription().c_str());
            wrefresh(contentWin);
            string newDesc = getInput(5, "Νέα περιγραφή:");
            if (!newDesc.empty()) {
                c->setDescription(newDesc);
                showMessage("Η περιγραφή ενημερώθηκε!", false);
            }
        } else if (choice == 1) {
            clearContent();
            mvwprintw(contentWin, 3, 2, "Τρέχον εξάμηνο: %d", c->getSemester());
            wrefresh(contentWin);
            int newSem = getIntInput(5, "Νέο εξάμηνο (1-12):", 1, 12);
            c->setSemester((unsigned int)newSem);
            showMessage("Το εξάμηνο ενημερώθηκε!", false);
        } else if (choice == 2) {
            clearContent();
            wrefresh(contentWin);
            string respCode = getInput(4, "Νέος κωδικός υπεύθυνου (Enter για αφαίρεση):");
            if (respCode.empty()) {
                c->setResponsible(nullptr);
                showMessage("Ο υπεύθυνος αφαιρέθηκε.", false);
            } else {
                Person* p = reg.findMember(respCode.c_str());
                if (p && p->getType() == "Professor") {
                    c->setResponsible(dynamic_cast<Professor*>(p));
                    showMessage("Ο υπεύθυνος ενημερώθηκε!", false);
                } else {
                    showMessage("Δεν βρέθηκε καθηγητής με κωδικό: " + respCode, true);
                }
            }
        }
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

void UI::removeCourse() {
    clearContent();
    wattron(contentWin, A_BOLD);
    mvwprintw(contentWin, 1, 2, "Διαγραφή Μαθήματος");
    wattroff(contentWin, A_BOLD);
    mvwprintw(contentWin, 2, 2, "------------------------------------------------");
    wrefresh(contentWin);

    string code = getInput(4, "Εισάγετε κωδικό μαθήματος:");
    if (code.empty()) return;

    Course* c = reg.findCourse(code);
    if (!c) {
        showMessage("Δεν βρέθηκε μάθημα με κωδικό: " + code, true);
        return;
    }

    if (!getConfirm("Διαγραφή μαθήματος [" + c->getCode() + "] " + c->getDescription() + ";")) return;

    try {
        reg.removeCourse(code);
        showMessage("Το μάθημα διαγράφηκε!", false);
    } catch (const exception& e) {
        showMessage(string("Σφάλμα: ") + e.what(), true);
    }
}

// EMAIL

void UI::emailMenu() {
    vector<string> opts = {
        "Αποστολή Email σε Όλους τους Φοιτητές",
        "Αποστολή Email σε Όλους τους Καθηγητές",
        "Πίσω"
    };

    while (true) {
        int c = runMenu("Αποστολή Email", opts);
        if (c == -1 || c == 2) return;

        clearContent();
        wattron(contentWin, A_BOLD);
        if (c == 0)
            mvwprintw(contentWin, 1, 2, "Αποστολή Email σε Φοιτητές");
        else
            mvwprintw(contentWin, 1, 2, "Αποστολή Email σε Καθηγητές");
        wattroff(contentWin, A_BOLD);
        mvwprintw(contentWin, 2, 2, "------------------------------------------------");

        int row = 4;
        int count = 0;

        for (int i = 0; i < reg.getMemberCount() && row < cRows; i++) {
            Person* p = reg.getMemberAt(i);
            string type = (c == 0) ? "Student" : "Professor";
            if (p->getType() != type) continue;

            if (c == 0) {
                mvwprintw(contentWin, row, 2, "[EMAIL] -> %s <%s@students.uniwa.gr>",
                          p->getFullName().c_str(), p->getCode());
            } else {
                mvwprintw(contentWin, row, 2, "[EMAIL] -> %s <%s@uniwa.gr>",
                          p->getFullName().c_str(), p->getCode());
            }
            row++;
            count++;
        }

        if (count == 0) {
            mvwprintw(contentWin, 4, 2, "Δεν υπάρχουν παραλήπτες.");
        } else {
            mvwprintw(contentWin, row + 1, 2, "Στάλθηκαν %d email.", count);
        }

        wrefresh(contentWin);
        waitKey();
    }
}

// ΑΡΧΕΙΑ

void UI::fileMenu() {
    vector<string> opts = {
        "Αποθήκευση σε CSV",
        "Φόρτωση από CSV",
        "Πίσω"
    };

    while (true) {
        int c = runMenu("Αποθήκευση / Φόρτωση", opts);
        if (c == -1 || c == 2) return;

        if (c == 0) {
            try {
                reg.saveToCSV(".");
                showMessage("Τα δεδομένα αποθηκεύτηκαν επιτυχώς στα αρχεία CSV!", false);
            } catch (const exception& e) {
                showMessage(string("Σφάλμα κατά την αποθήκευση: ") + e.what(), true);
            }
        } else {
            if (!getConfirm("Η φόρτωση θα αντικαταστήσει τα τρέχοντα δεδομένα. Συνέχεια;")) continue;
            try {
                reg.loadFromCSV(".");
                showMessage("Τα δεδομένα φορτώθηκαν επιτυχώς από τα αρχεία CSV!", false);
            } catch (const exception& e) {
                showMessage(string("Σφάλμα κατά τη φόρτωση: ") + e.what(), true);
            }
        }
    }
}

// MAIN RUN

void UI::run() {
    drawHeader();

    vector<string> mainOpts = {
        "Διαχείριση Φοιτητών",
        "Διαχείριση Καθηγητών",
        "Διαχείριση Μαθημάτων",
        "Αποστολή Email",
        "Αποθήκευση / Φόρτωση CSV",
        "Έξοδος"
    };

    while (true) {
        int c = runMenu("Κεντρικό Μενού", mainOpts);
        if (c == -1 || c == 5) {
            if (getConfirm("Έξοδος από την εφαρμογή;")) break;
        } else {
            switch (c) {
                case 0: studentsMenu();  break;
                case 1: professorsMenu(); break;
                case 2: coursesMenu();   break;
                case 3: emailMenu();     break;
                case 4: fileMenu();      break;
            }
            drawHeader();
        }
    }
}
