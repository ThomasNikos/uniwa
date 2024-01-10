#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

class MapManager {
private:
	std::vector<std::string> maps;
	
public:
	MapManager();
	~MapManager();
	
	void Load(const char*);
	void Print() const;
	std::string Get(const unsigned int &) const;
	std::string GetRandom() const;
};
MapManager::MapManager() {}
MapManager::~MapManager() {}
void MapManager::Load(const char *filename) {
	std::ifstream ifile(filename);
	std::string line;
	std::string map;
	if (ifile.is_open()) {
		while(std::getline(ifile, line)) map += line + "\n";
		ifile.close();
	}
	else throw "File could not be opened.";
	maps.push_back(map);
}
void MapManager::Print() const {
	std::vector<std::string>::const_iterator itr = maps.begin();
	for (itr; itr != maps.end(); itr++) 
		std::cout << *itr << std::endl;
}
std::string MapManager::Get(const unsigned int &index) const {
	if (index > maps.size()) throw "Index out of bounds";
	return maps[index];
}
std::string MapManager::GetRandom() const {
	return maps[rand() % maps.size()];
}

int main(int argc, char** argv) {
	srand(time(NULL));
	
	try {
	
		MapManager mm;
		mm.Load("map1.txt");
		mm.Load("map2.txt");
		mm.Load("map3.txt");
		mm.Print();
		
		std::string map = mm.Get(2);
		std::string map2 = mm.GetRandom();
		
		std::cout << map << std::endl;
		std::cout << map2 << std::endl;
	}
	catch(const char *err) {
		std::cout << err << std::endl;
	}
	
	return 0;
}
