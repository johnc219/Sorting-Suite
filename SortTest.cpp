#include "Sorting.h"
#include <iostream>

#define LENGTH 20	// length of the test vector

// Test user-defined sorting algorithms
int main(){
	std::vector<int> v;
	for (int i = 0; i < LENGTH; i++){
		v.push_back((LENGTH-i)%10);
	}
	Sorting::quick_sort_in_place(v);
	for (int i = 0; i < LENGTH; i++){
		std::cout << v[i] << std::endl;
	}
	// Exit program
	return 0;
}