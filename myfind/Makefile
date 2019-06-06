CXX = g++
CXXFLAGS = -Wall -g
TARGET = myfind

$(TARGET): find.o predicate.o predicatefactory.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) find.o predicate.o predicatefactory.o

find.o: find.cpp
	$(CXX) $(CXXFLAGS) -c $<

predicate.o: predicate.cpp
	$(CXX) $(CXXFLAGS) -c $<

predicatefactory.o: predicatefactory.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o
	rm -f $(TARGET)

