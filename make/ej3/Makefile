LD = $(CXX)
TARGET = tp

# Si FUENTES no está seteado, lo seteo acá
FUENTES ?= $(wildcard *.cpp) 
OBJS = $(patsubst %.cpp,%.o,$(FUENTES))

all: $(TARGET)

%.o: %.cpp
	echo "Target $@ -> Compilando $<"
	$(CXX) -c $<

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS) 

clean:
	$(RM) *.o $(TARGET)

.PHONY: all clean
