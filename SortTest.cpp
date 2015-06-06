#include "Sorting.h"

#define OPTIONS 5
#define TEST_VECTORS 10	// number of vectors to test
#define LOWER 0
#define UPPER 100
#define LENGTH 20	// length of the test vector
#define TYPE int

// Test user-defined sorting algorithms
int main(){

	srand(time(NULL));
	typedef TYPE T;

	std::vector<T> input;
	std::vector<T> output;
	int errors = 0;

	std::cout << "Testing " << TEST_VECTORS << " vectors of length " << LENGTH << " with range " << LOWER << "-" << UPPER << std::endl;

	for (int i = 0; i < TEST_VECTORS; i++){
		
		Sorting::fill_vector<T>(input, LENGTH, LOWER, UPPER);
		
		output = Sorting::bubble_sort(input);
		if (!Sorting::is_sorted<T>(output)){
			errors++;
		}

		output = Sorting::selection_sort(input);
		if (!Sorting::is_sorted<T>(output)){
			errors++;
		}

		output = Sorting::insertion_sort(input);
		if (!Sorting::is_sorted<T>(output)){
			errors++;
		}

		output = Sorting::merge_sort(input);
		if (!Sorting::is_sorted<T>(output)){
			errors++;
		}

		output = Sorting::quick_sort(input);
		if (!Sorting::is_sorted<T>(output)){
			errors++;
		}

		output = input;
		Sorting::quick_sort_in_place(output);
		if (!Sorting::is_sorted<T>(output)){
			errors++;
		}

	}

	std::cout << "Errors: " << errors << std::endl;

	// Exit 
	return 0;
}