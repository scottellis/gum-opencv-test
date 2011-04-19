CC = gcc
CFLAGS = -Wall -Wno-unused-function

CXXFLAGS += `pkg-config opencv --cflags`

LDFLAGS += `pkg-config opencv --libs`

TARGET = flip


$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) $(TARGET).c -o $(TARGET)
	
	
clean:
	rm -f $(TARGET) flipped.jpg

