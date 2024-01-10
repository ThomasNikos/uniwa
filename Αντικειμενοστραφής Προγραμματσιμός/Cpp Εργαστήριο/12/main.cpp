#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class cell{
        string value;
        string type;
    public:
        string get_value(){
            return value;
        }
        string get_type(){
            return type;
        }
        void set_value(string value_in){
            value = value_in;
        }
        void set_type(string type_in){
            type = type_in;
        }

};

class paper{
        cell * papert[10][20];
        int xmax,ymax;
    public:
        void setx(int x_in){
            xmax = x_in;
        }
        void sety(int y_in){
            ymax = y_in;
        }
        void addcell(int z, int e, cell & ce){
            if(z>xmax)
                xmax = z+1;
            if(e>ymax)
                ymax = e+1;
                papert[z][e] = new cell(ce);
        }
        void print(){
                ofstream file;
                file.open("nikos.csv");
                int y = -1,count=0;
                for(int z = 0;z<=xmax;z++){
                    y++;
                    for(int e = 0;e<=ymax;e++){
                        if(papert[z][e]->get_value() == " ");
                            count++;

                        if(y!=0){
                            file<< endl;
                            y=0;
                        }
                        file << papert[e][z]->get_value() << ';';
                    }
                }
        }
        cell get_cell(int z, int e){
            return *papert[z][e];
        }
        void delete_cell(cell & ce, int z, int e){
                papert[z][e] = new cell(ce);
        }
};

int main(int argc, char ** argv){
    paper nikos;
    cell cell1;
    cell empty;
    cell cell2;
    for(int x = 0;x<10;x++){
        for(int y = 0;y<20;y++){
            nikos.addcell(x,y,empty);
        }
    }
    nikos.setx(0);
    nikos.sety(0);
    cell1.set_type("int");
    cell1.set_value("int");
    cell2.set_type("float");
    cell2.set_value("float");
    nikos.addcell(1,0,cell2);
    nikos.addcell(1,2,cell2); 
    nikos.addcell(3,0,cell2); 
    cout << nikos.get_cell(0,0).get_value() << endl << nikos.get_cell(0,0).get_type();
    nikos.print();

}