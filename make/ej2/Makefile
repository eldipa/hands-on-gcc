LD = $(CXX)
TARGET = tp

FUENTES = main.cpp class0.cpp class1.cpp class2.cpp class3.cpp
OBJS = main.o class0.o class1.o class2.o class3.o

all: $(TARGET)

%.o: %.cpp
	echo "Target $@ -> Compilando $<"
	$(CXX) -c $<

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS) 

clean:
	$(RM) *.o $(TARGET)

.PHONY: all clean
