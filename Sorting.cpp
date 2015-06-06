#include "Sorting.h"
#include <list>
#include <iostream>

/************************************  bubble_sort  *************************************/

// worst case	Theta(n^2)
// best case	Theta(n)
std::vector<int> Sorting::bubble_sort(std::vector<int> A){

	// outer loop, after one loop one value will be in correct place
	for (int i = 0; i < A.size(); i++){
		bool swapped = false;

		// inner loop, swap adjacent items if left one is greater than right one 
		for (int j = 0; j < A.size()-1; j++){
			if (A[j] > A[j+1]){
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				swapped = true;
			}
		}

		// break outer loop if no changes were made in the outer loop iteration (sorting finished)
		if (!swapped){
			break;
		}
	}

	// A is now sorted
	return A;
}

/************************************  selection_sort  *************************************/

// worst case	Theta(n^2)
// best case	Theta(n^2)
std::vector<int> Sorting::selection_sort(std::vector<int> A){

	// get the index of the minimum value between the i'th value and the last value
	for (int i = 0; i < A.size()-1; i++){
		int min = i;

		// update the minimum index if we find a smaller value than the value at the current min index
		for (int j = i + 1; j < A.size(); j++){
			if (A[j] < A[min]){
				min = j;
			}
		}

		// swap the i'th value with minimum value found in this iteration
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}

	// A is now sorted
	return A;
}

/************************************  insertion_sort  *************************************/

// worst case:	Theta(n^2)
// best case:	Theta(n)
std::vector<int> Sorting::insertion_sort(std::vector<int> A){

	// "insert" each value starting from the 2nd value in the array
	for (int i = 1; i < A.size(); i++){

		// save a copy of the i'th value so we can place it accordingly at the end of the iteration
		int val = A[i];

		// look at the values to the left of 'i' and shift values one to the right until we see a value less than our stored copy or until we've shifted all values
		int j = i - 1;
		while (j >= 0 && A[j] > val){
			A[j+1] = A[j];
			j--;
		}

		// 'j+1' holds the index where the copy should be placed. Everything to the left of this index is sorted. 
		A[j+1] = val;
	}

	// A is now sorted
	return A;
}

/************************************  merge_sort  *************************************/

// worst case:	Theta(nlogn)
// best case:	Theta(nlogn)
std::vector<int> Sorting::merge_sort(std::vector<int> A){

	// stop recursively calling once the argument is of size 1, and return that 1-item argument
	if (A.size() == 1){
		return A;
	}

	// otherwise, split the argument into two vectors
	int middle = (A.size()+1) / 2;
	std::vector<int> ALeft(A.begin(), A.begin()+middle);
	std::vector<int> ARight(A.begin()+middle, A.end());

	// recursively call merge_sort on each half of the argument
	ALeft = Sorting::merge_sort(ALeft);
	ARight = Sorting::merge_sort(ARight);

	// merge the two sorted halves into one sorted vector
	return Sorting::merge(ALeft, ARight);
}

std::vector<int> Sorting::merge(std::vector<int> ALeft, std::vector<int> ARight){
	
	// The merged vector that will be sorted (as long as the arguments are sorted)
	std::vector<int> result;
	
	// Method 1
	// advantage: the push_back method is amortized constant time
	//			  and as a result, the merge operation takes only Theta(n)
	
	// keep track of the size of each "half" (the left vector and the right vector)
	int ALSize = ALeft.size();
	int ARSize = ARight.size();

	// keep track of which values in each vector are to be pushed_back next into the result
	int ALIndex = 0;
	int ARIndex = 0;

	// keep on pushing values into the result while there are any that haven't been pushed yet
	while (ALSize > 0 || ARSize > 0){
		
		// if both halves still have values to be pushed, push the smaller one. If they're equal, push both
		if (ALSize > 0 && ARSize > 0){
			if (ALeft[ALIndex] < ARight[ARIndex]){
				result.push_back(ALeft[ALIndex]);
				ALSize--;
				ALIndex++;
			} else if (ALeft[ALIndex] > ARight[ARIndex]){
				result.push_back(ARight[ARIndex]);
				ARSize--;
				ARIndex++;
			} else{
				result.push_back(ALeft[ALIndex]);
				result.push_back(ARight[ARIndex]);
				ALSize--;
				ARSize--;
				ALIndex++;
				ARIndex++;
			}
		
		// else if only the left half has values remaining to be pushed, push them
		} else if (ALSize > 0){
			result.push_back(ALeft[ALIndex]);
			ALIndex++;
			ALSize--;
		
		// else if only the right half has values remaining to be pushed, push them
		} else if (ARSize > 0){
			result.push_back(ARight[ARIndex]);
			ARIndex++;
			ARSize--;
		}
	}
		
	/*
	// For readability
	// downside: each time we erase, we have to copy all items to the right of the 1st element into a new array, resulting in an O(n) operation
	//			 and as a result the merge operation takes O(n^2) instead of O(n)
	while (ALeft.size() > 0 || ARight.size() > 0){
		if (ALeft.size() > 0 && ARight.size() > 0){
			if (ALeft.front() < ARight.front()){
				result.push_back(ALeft.front());
				ALeft.erase(ALeft.begin());
			} else if (ALeft.front() > ARight.front()){
				result.push_back(ARight.front());
				ARight.erase(ARight.begin());
			} else{
				result.push_back(ALeft.front());
				ALeft.erase(ALeft.begin());
				result.push_back(ARight.front());
				ARight.erase(ARight.begin());
			}
		} else if (ALeft.size() > 0){
			result.push_back(ALeft.front());
			ALeft.erase(ALeft.begin());			
		} else if (ARight.size() > 0){
			result.push_back(ARight.front());
			ARight.erase(ARight.begin());
		}
	}
	*/

	// result contains the merged and sorted vector
	return result;

}

/************************************  quick_sort  *************************************/

// worst case:	Theta(n^2)
// best case:	Theta(nlogn)
std::vector<int> Sorting::quick_sort(std::vector<int> A, int left, int right){
	
	// When quicksort is first called, no argument other than A needs to be given. 
	// The index of the rightmost element is assigned to 'right'
	if (right == -100){
		right = A.size()-1;
	}

	// if the subvector to be worked on is of size > 1, recurse further. Otherwise don't do anything
	if (left < right){

		// in the subvector, find at what index the right-most value was placed 
		int pivot = Sorting::partition(A, left, right);

		// recurse on the subvector left of the pivot and on the subvector right of the pivot
		A = Sorting::quick_sort(A, left, pivot-1);
		A = Sorting::quick_sort(A, pivot+1, right); 
	}

	// A is now the sorted subvector
	return A;
}

// worst case:	Theta(n^2) (already sorted or reverse sorted):
// best case:	Theta(nlogn)
// The vector is sorted in place, no extra vectors are needed (saves memory)
void Sorting::quick_sort_in_place(std::vector<int>& A, int left, int right){
	
	// When quicksort is first called, no argument other than A needs to be given. 
	// The index of the rightmost element is assigned to 'right'
	if (right == -100){
		right = A.size()-1;
	}

	// if the subvector to be worked on is of size > 1, recurse further. Otherwise don't do anything
	if (left < right){

		// in the subvector, find at what index the right-most value was placed 
		int pivot = Sorting::partition(A, left, right);

		// recurse on the subvector left of the pivot and on the subvector right of the pivot
		Sorting::quick_sort_in_place(A, left, pivot-1);
		Sorting::quick_sort_in_place(A, pivot+1, right); 
	}
}

// complexity:	Theta(n)
int Sorting::partition(std::vector<int>& A, int left, int right){
	
	// initialize index to the left-most index 
	int index = left;

	// everything to the left of index is <= to the pivot (right-most element)
	for (int i = left; i < right; i++){
		if (A[i] <= A[right]){
			int temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
	}

	// swap the pivot with the value at the updated index
	int temp = A[index];
	A[index] = A[right];
	A[right] = temp;

	// this is where A will be partitioned
	return index;
}

/************************************  counting_sort  *************************************/

// worst case:	Theta(n+m) (m is the range of values in A)
// best case:	Theta(n+m)
std::vector<int> Sorting::counting_sort(std::vector<int> A){
	
	// return empty vector if input is empty
	if (A.empty()){
		return A;
	}
		
	// get min and max values
	int min = A[0];
	int max = A[0];
	for (int i = 0; i < A.size(); i++){
		if (A[i] > max){
			max = A[i];
		}
		if (A[i] < min){
			min = A[i];
		}
	}

	// fill a new vector of counters with zeros to hold a counter for each unique numbers in A
	int diff = max - min;
	std::vector<int> count(diff+1, 0);

	// as we iterate through A, update the counters by incrementing their corresponding values 
	// using min as an offset allows us to sort vectors with negative numbers 
	for (int i = 0; i < A.size(); i++){
		count[A[i]-min]++;
	}

	// empty A so that it can be rebuilt in sorted order
	A.clear();

	// iterate through the counters, pushing index i+min (offset taken care of) as many times as they were counted
	for (int i = 0; i < count.size(); i++){
		while (count[i] > 0){
			A.push_back(i+min);
			count[i]--;
		}
	}

	// A is now sorted
	return A;
}

/************************************  radix_sort (LSD) *************************************/

// worst case:	Theta(k(n+a)) where k is the max number of digits, n is the number of items in A, and a is the alphabet count
// best case:	Theta(k(n+a))
// supports only bases 1 through 10
// supports nonnegative integers only
std::vector<int> Sorting::radix_sort(std::vector<int> A, int base){
	
	// check for empty input vector or invalid base
	if (A.empty() || base < 1 || base > 10){
		std::cout << "Error: empty vector or invalid/unsupported base" << std::endl; 
		return A;
	}

	// vector of buckets. 1 bucket for each possible digit value
	std::vector<std::list<int> > buckets(base, std::list<int>());

	// determine the max in order to determine number of digits we must iterate through
	int max = A[0];
	for (int i = 0; i < A.size(); i++){
		if (A[i] > max){
			max = A[i];
		}
	}

	// determine number of digits of the max number
	int digits = 0;
	while (max > 0){
		max = max / 10;
		digits++;
	}

	// mod by 10 to get the right most digit. divide by divisor (n^10) to cut off n digits
	const int mod = 10;
	int divisor = 1;
	
	// place into buckets and then pull out from buckets as many times as there are digits in the max number
	for (int i = 0; i < digits; i++){

		// place into buckets
		for (int j = 0; j < A.size(); j++){
			int index = (A[j] / divisor) % mod;
			(buckets[index]).push_back(A[j]);
		}

		// update A by pulling out from the buckets
		int location = 0;
		for (int j = 0; j < buckets.size(); j++){
			while (!(buckets[j]).empty()){
				A[location] = (buckets[j]).front();
				(buckets[j]).pop_front();
				location++;
			}
		}

		// update divisor in order to look at the next LSD in next iteration
		divisor *= 10;
	}

	// A is now sorted
	return A;
}

// For numbers evenly distributed from (0, 1]
// worst case:	Theta(n^2)
// best case:	Theta(n+k)
std::vector<float> Sorting::bucket_sort(std::vector<float> A){

	// return empty vector if input is empty
	if (A.empty()){
		return A;
	}
	
	// set up buckets
	const int num_buckets = A.size();
	std::vector<std::list<float> > buckets(num_buckets, std::list<float>());

	// place elements in corresponding buckets
	for (int i = 0; i < A.size(); i++){
		int index = static_cast<int>(A[i] * static_cast<float>(num_buckets));
		(buckets[index]).push_back(A[i]);
	} 

	// sort buckets and rewrite A in sorted order
	int location = 0;
	for (int i = 0; i < buckets.size(); i++){
		(buckets[i]).sort();
		while (!(buckets[i]).empty()){
			A[location] = (buckets[i]).front();
			buckets[i].pop_front();
			location++;
		}
	}

	// A is now sorted
	return A;
}


// function to print out contents of the vector A
void Sorting::print_vector(std::vector<int> A){
	for (int i = 0; i < A.size(); i++){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}











