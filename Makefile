CC 	 = gcc	
CFLAGS   = --std=c99 -Wall
TARGET   = bin/test
OBJFILES = bin/test.o bin/list.o
  
$(TARGET): $(OBJFILES)  
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) 

test.o: test.c 
	gcc --std=c99 -c test.c -o bin/test.o

list.o: list.c   list.h
	gcc --std=c99 -c list.c -o bin/list.o
clean: 
	rm -f $(OBJFILES) $(TARGET)
