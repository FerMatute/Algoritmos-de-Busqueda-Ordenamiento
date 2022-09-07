#ifndef SELECTION_H
#define SELECTION_H

#include "header.h"
#include <vector>

// =================================================================
// Performs the selection sort algorithm on a vector.
//
// @param A, a vector of T elements.
// =================================================================
template <class T>
int selectionSort(std::vector<T> &v) {
	int pos;
	int counter = 0;
	for(int i = v.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(v[j] > v[pos]){
				pos = j;
			}
		}

		if (pos != i){
			counter++;
			swap(v, i, pos);
		}
	}
	return counter;
}

#endif /* SELECTION_H */
