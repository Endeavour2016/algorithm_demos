#ifndef _COMMON_H_
#define _COMMON_H_

#include <vector>

// swap arr[i] and arr[j]
void ArraySwap(int arr[], int i, int j);
void VectorSwap(std::vector<int>& vec, int i, int j);
void Printer(const std::vector<int>& vec);
void Printer(int arr[], int n);

#endif