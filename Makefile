CC 	 = gcc	#compiler name
CFLAGS   = --std=c99 -Wall # compress all warning, choose your own compile flags (if any)
TARGET   = test
OBJFILES = test.o list.o
  
$(TARGET): $(OBJFILES)  
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) 

test.o: test.c       # Meaning: target test.o depends on test.c 
	gcc --std=c99 -c test.c         # Command to make the target

list.o: list.c   list.h #target list.o depends on list.c and indirectly on list.h	
	gcc --std=c99 -c list.c
clean: 
	rm -f $(OBJFILES) $(TARGET)
