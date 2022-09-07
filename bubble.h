#ifndef BUBBLE_H
#define BUBBLE_H

#include "header.h"
#include <vector>

// =================================================================
// Performs the bubble sort algorithm on an vector.
//
// @param v, a vector of T elements.
// =================================================================
template <class T>
int bubbleSort(std::vector<T> &v) {
	int counter = 0;
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j] > v[j + 1]){
				counter++;
				swap(v, j, j + 1);
			}
		}
	}
	return counter;
}

#endif /* BUBBLE_H */
