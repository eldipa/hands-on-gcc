LD = $(CXX)
TARGET = tp

FUENTES ?= $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(FUENTES))

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c $<

%.dep : %.cpp %.h
	$(CXX) -MM $< > $@

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS) 

-include $(OBJS:%.o=%.dep)

clean:
	$(RM) *.o *.dep $(TARGET)

.PHONY: all clean
