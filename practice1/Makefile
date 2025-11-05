TARGET = a
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
GXX = g++

$(TARGET): $(OBJECTS)
	$(GXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(GXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)