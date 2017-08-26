TARGET = demo

all: demo.zip $(TARGET)

demo.zip: fooFile barFile
	zip $@ $?

$(TARGET): main.cpp
	g++ -o $(TARGET) main.cpp -lzip

static:
	g++ -o $(TARGET)-static main.cpp -Wl,-Bstatic -lzip -lz -Wl,-Bdynamic

clean:
	$(RM) demo.zip $(TARGET) $(TARGET)-static

.PHONY: all clean static