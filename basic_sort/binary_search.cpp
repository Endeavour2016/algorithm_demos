/*
 * @Author: zlm 
 * @Date: 2021-10-30 21:29:09 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-30 21:29:34
 */

#include <iostream>
using namespace std;


// 二分查找，找到该值在数组中的下标，否则为-1
// 参与查找的数组为有序
int BinarySerach(int array[], int length, int key) {
  int left = 0;
  // 这里不能使用sizeof(array)，因为array 是形参，采用这个关键字返回
  // 的是size of (int*)即指针的大小，将始终为4个字节
  int right = length - 1;

  // 这里只能是<=
  while (left <= right) {
      int mid = (left + right) / 2;
      if (array[mid] == key) {
        return mid;
      } else if (array[mid] < key) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6, 8, 12, 13, 14, 16};
  int length = sizeof(a) / sizeof(a[0]);
  int key = 12;
  int index = BinarySerach(a, length, key);
  cout << "the array is: " << endl;
  for (int i = 0; i < length; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "the index of key in a is " << index << endl;
}