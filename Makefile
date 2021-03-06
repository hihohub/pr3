CC 	 = gcc	
CFLAGS   = --std=c99 -Wall
TARGET   = bin/test
OBJFILES = bin/test.o bin/list.o
  
$(TARGET): $(OBJFILES)  
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) 

bin/test.o: test.c 
	mkdir -p bin
	gcc --std=c99 -c test.c -o bin/test.o

bin/list.o: list.c   list.h
	mkdir -p bin
	gcc --std=c99 -c list.c -o bin/list.o
clean: 
	rm -f $(OBJFILES) $(TARGET)
	rmdir bin
