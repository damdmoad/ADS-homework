CXX = g++
TARGET = lovekunkun
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CFLAGS = -Wall 

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
