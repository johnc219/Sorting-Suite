
# Rule to get the executable
SortTest : SortTest.o Sorting.o
	g++ -o SortTest SortTest.o Sorting.o

# Rule to get object file
SortTest.o : SortTest.cpp Sorting.h
	g++ -c SortTest.cpp

# Rule to get object file
Sorting.o : Sorting.cpp Sorting.h
	g++ -c Sorting.cpp

# To run compile and link if necessasry and then run the program
# $ make run 
.PHONY: run
run : SortTest
	./SortTest

# To remove the object files and the executable
# $ make clean
.PHONY: clean
clean :
	rm *.o SortTest