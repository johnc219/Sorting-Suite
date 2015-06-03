#include "Sorting.h"
#include <iostream>

#define LENGTH 20	// length of the test vector

// Test user-defined sorting algorithms
int main(){
	std::vector<int> v;
	for (int i = 0; i < LENGTH; i++){
		v.push_back(LENGTH-i);
	}
	v = Sorting::merge_sort(v);
	for (int i = 0; i < LENGTH; i++){
		std::cout << v[i] << std::endl;
	}
	return 0;
}