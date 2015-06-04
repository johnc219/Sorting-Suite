#include "Sorting.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define LENGTH 20	// length of the test vector

// Test user-defined sorting algorithms
int main(){
	
	srand(time(NULL));

	std::vector<int> v;
	for (int i = 0; i < LENGTH; i++){
		int num = rand() % 100;
		v.push_back(num);
	}

	std::cout << "Before: " << std::endl;
	Sorting::print_vector(v);

	std::cout << "In progress:" << std::endl;
	v = Sorting::radix_sort(v);

	std::cout << "After: " << std::endl;
	Sorting::print_vector(v);

	// Exit 
	return 0;
}