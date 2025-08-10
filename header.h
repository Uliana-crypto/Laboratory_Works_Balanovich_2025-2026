#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <fstream> 
#include <string>
#include <windows.h>

void printArray(int32_t*, int32_t);
void bubleSort(int32_t*, int32_t, char);
void enterArray(int32_t*, int32_t&);
void enterSize(int32_t&);
void getDirection(char&);
void insertionSort(int32_t*, int32_t, char);
void quickSort(int32_t*, int32_t, int32_t, char);
void selectionSort(int32_t*, int32_t, char);
void mergeSort(int32_t*, int32_t, int32_t, char);
void merge(int32_t*, int32_t, int32_t, int32_t, char);
void heapSort(int32_t*, int32_t, char);
void heapify(int32_t*, int32_t, int32_t, char);
void combSort(int32_t*, int32_t, char);
void shellSort(int32_t*, int32_t, char);

#endif
