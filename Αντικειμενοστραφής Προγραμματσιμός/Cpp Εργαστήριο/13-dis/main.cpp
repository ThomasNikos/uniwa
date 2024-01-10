// A - 12

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define MAX_ROWS 10000
#define MAX_COLS 200

class Cell {
public:
	std::string type;
	std::string value;
	
	Cell();
	Cell(std::string, std::string);
	~Cell();
	
	Cell operator=(const Cell &);
};
Cell::Cell() {}
Cell::Cell(std::string type, std::string value)
: type(type), value(value) {}
Cell::~Cell() {}

Cell Cell::operator=(const Cell &cell) {
	return Cell(cell.type, cell.value);
}

class Spreadsheet {
private:
	Cell ***cells;
	unsigned int rows;
	unsigned int cols;
	
public:
	Spreadsheet();
	~Spreadsheet();
	
	void Place(Cell *, unsigned int, unsigned int);
	Cell *Fetch(unsigned int, unsigned int);
	void Remove(unsigned int, unsigned int);
	void Save();
};
Spreadsheet::Spreadsheet() : rows(0), cols(0) {
	cells = new Cell**[rows];
	for (int r = 0; r < rows; r++)
		cells[r] = new Cell*[cols];
	
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			cells[r][c] = NULL;
		}
	}
}
Spreadsheet::~Spreadsheet() {
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			delete cells[r][c];
	for (int r = 0; r < rows; r++)
		delete[] cells[r];
	delete[] cells;
}

void Spreadsheet::Place(Cell *cell, unsigned int x, unsigned int y) {
	if (y > 10000 || x > 200) return;
	
	if (rows >= y && cols >= x) {
		cells[y - 1][x - 1] = cell;
		return;
	}
	
	unsigned int oldRows = rows;
	unsigned int oldCols = cols;
	
	rows = std::max(rows, y);
	cols = std::max(cols, x);
	
	// Allocating memory for tmp array of Cell pointers
	Cell ***tmp = new Cell**[rows];
	for (int r = 0; r < rows; r++)
		tmp[r] = new Cell*[cols];
		
	// Init tmp with NULL
	for (int r = 0; r < rows; r++) 
		for (int c = 0; c < cols; c++) 
			tmp[r][c] = NULL;
			
	// Point each pointer to a cell
	for (int r = 0; r < oldRows; r++) 
		for (int c = 0; c < oldCols; c++)
			tmp[r][c] = cells[r][c];
	
	// Set new element
	tmp[y - 1][x - 1] = cell;
	
	// Point current ***pointer to the new array
	cells = tmp;
}
Cell *Spreadsheet::Fetch(unsigned int x, unsigned int y) {
	if (rows >= y && cols >= x) {
		return cells[y - 1][x - 1];
	} else return new Cell();
}
void Spreadsheet::Remove(unsigned int x, unsigned int y) {
	if (rows >= y && cols >= x) {
		cells[y - 1][x - 1] = NULL;
	}
}
void Spreadsheet::Save() {
	std::ostringstream oss;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (cells[i][j] == NULL) oss << ";";
			else oss << cells[i][j]->value << ";";
		}
		oss << std::endl;
	}
	std::cout << oss.str();
	
	std::ofstream ofile("spreadsheet.csv");
	if (ofile.is_open()) {
		ofile << oss.str();
		ofile.close();
	}
}

int main(int argc, char** argv) {
	Spreadsheet ss;
	ss.Place(new Cell("string", "13"), 1, 1);
	ss.Place(new Cell("string", "13"), 15, 12);
	ss.Place(new Cell("string", "12"), 1, 2);
	ss.Place(new Cell("string", "16"), 4, 4);
	ss.Place(new Cell("string", "15"), 20, 1);
	ss.Place(new Cell("int", "1"), 200, 10000);
	ss.Place(new Cell("int", "2"), 200, 10001);
	ss.Place(new Cell("int", "3"), 201, 10001);
	std::cout << "Value is: " << ss.Fetch(1, 2)->value << std::endl;
	ss.Remove(4, 4);
	ss.Save();
	
	return 0;
}
