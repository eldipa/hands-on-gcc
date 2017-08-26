LD = $(CXX)
TARGET = tp

FUENTES = main.cpp
OBJS = main.o

all: $(TARGET)

$(OBJS): $(FUENTES)
	$(CXX) -c $(FUENTES)

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS) 

clean:
	$(RM) *.o $(TARGET)

.PHONY: all clean
