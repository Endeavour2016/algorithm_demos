/*
 * @Author: zlm 
 * @Date: 2021-10-23 11:36:48 
 * @Last Modified by:   zlm 
 * @Last Modified time: 2021-10-23 11:36:48 
 */

#include "./common.h"
#include <cstdio>
#include <iostream>

using namespace std;

void ArraySwap(int arr[], int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void VectorSwap(vector<int>& vec, int i, int j) {
  int tmp = vec[i];
  vec[i] = vec[j];
  vec[j] = tmp;
}

void Printer(const vector<int>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ", ";
  }
  cout << endl;
}

void Printer(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/*
int main() {
  std::cout << "test build!\n";
  system("pause");
  return 0;
}*/
