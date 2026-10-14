CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = Person.o Course.o Professor.o Student.o Foititologio.o main.o

thomas3: $(OBJS)
	$(CXX) $(CXXFLAGS) -o thomas3 $(OBJS)

Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp

Course.o: Course.cpp Course.h Professor.h
	$(CXX) $(CXXFLAGS) -c Course.cpp

Professor.o: Professor.cpp Professor.h Person.h Course.h
	$(CXX) $(CXXFLAGS) -c Professor.cpp

Student.o: Student.cpp Student.h Person.h Course.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

Foititologio.o: Foititologio.cpp Foititologio.h Student.h Professor.h Course.h
	$(CXX) $(CXXFLAGS) -c Foititologio.cpp

main.o: main.cpp Foititologio.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) thomas3 *.csv
