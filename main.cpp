// =================================================================
//
// File: main.cpp
// Author: Fernando Josue Matute Soto  -  A00833375
// Date: 06/09/22
//
// =================================================================
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  vector <int> bubble, selection, insertion;
  int search, get;

  ifstream input;
  ofstream mysolution;

  if (argc != 3){
    cout<< "Error"<<endl;
    exit(EXIT_FAILURE);
  }

  input.open(argv[1]);
  if (!input.is_open()){
    cout << "Error al abrir el archivo\n";
    exit(EXIT_FAILURE);
  }

  mysolution.open(argv[2]);
  int num;
  input>>num;
  bubble.resize(num);
  for (int i=0; i<num; i++){
    input>>bubble[i];
  }

  selection.assign(bubble.begin(),bubble.end());
  insertion.assign(bubble.begin(),bubble.end());
  //Escribimos en las copias de los archivos
  mysolution<<bubbleSort(bubble)<<" "<<selectionSort(selection)<<" "<<insertionSort(insertion)<<"\n\n";

  input>>search;

  pair<int, int> PAIR;

  for (int i=0; i<search; i++){
    input>>get;
    PAIR = sequentialSearch(bubble,get);
    mysolution<<PAIR.second<<" "<<PAIR.first<<" ";

    PAIR = binarySearch(bubble, get);
    mysolution<<PAIR.first<<"\n";
  }
  
  input.close();
  mysolution.close();
	return 0;
}
