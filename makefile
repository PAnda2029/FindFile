CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = search_program
OBJECTS = main.o FindFile.o

$(TARGET): $(OBJECTS)
    $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

main.o: main.cpp FindFile.h
    $(CXX) $(CXXFLAGS) -c main.cpp

FindFile.o: FindFile.cpp FindFile.h
    $(CXX) $(CXXFLAGS) -c FindFile.cpp

clean:
    rm -f $(OBJECTS) $(TARGET)