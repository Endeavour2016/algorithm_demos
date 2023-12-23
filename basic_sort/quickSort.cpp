/*
 * @Author: zlm 
 * @Date: 2021-10-23 11:36:35 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-30 21:28:44
 */

#include <iostream>
#include <vector>
#include "./common.h"

using namespace std;


// 数据划分：通过双重循环方式实现
int Partition(vector<int>& arr, int left, int right) {
  int pivot = arr[left];
  while (left < right) {
    while (left < right && arr[right] >= pivot) {
      right--;
    }
    arr[left] = arr[right];   // 小于基准的值移动到左侧

    while (left < right && arr[left] < pivot) {
      left++;
    }
    arr[right] = arr[left];   // >=基准的值放在右边
  }
  // left 和 right相遇时，left左边的值均小于pivot，右边的值均>=基准
  // 此时的位置即为基准值的位置
  arr[left] = pivot;
  return left;
}



int Partition(int r[], int low, int high) {
    int pivot = r[low];
    while (low < high) {
        while(low < high && r[high] >= pivot) {   // 右侧扫描，较小的数交换到左侧
            high--; 
        }
        ArraySwap(r, low, high);

        while(low < high && r[low] <= pivot) {   // 左侧扫描，不符合条件右移
            low++;
        }
        ArraySwap(r, low, high); 
    }
    return low;  // 返回基准值的位置index
}


// 数据划分：单循环方式
int Partition2(vector<int>& vec, int left, int right) {
  int pivot = left;
  int location = pivot + 1;  // location指向所有比pivot小的序列的下一个位置
  for (int i = left; i <= right; ++i) {
    if (vec[i] < vec[pivot]) {
      // 小于基准的元素，放到location指向的位置
      VectorSwap(vec, i, location);
      ++location;
    }
  }

  // 将基准元素放到合适的位置
  VectorSwap(vec, pivot, location-1);
  return (location - 1);
}


void QuickSort(vector<int>& r, int low, int high) {
  if (low < high) {
    int pivot = Partition2(r, low, high);  // 每趟排好一个元素
    QuickSort(r, low, pivot - 1);
    QuickSort(r, pivot + 1, high);
  }
}



int main() {
  vector<int> data = {49,38,65,97,10,22,33,9,2,76,13,27,49,31,50}; 
  int low = 0, high = data.size() - 1; 
  cout << "before sorted, the data is :" << endl;

  for (int i = 0; i < data.size(); i++) {
    cout << data[i] << "  ";
  }

  cout << endl << endl;
  
  QuickSort(data, low, high);

  cout << "After sorted, the data is: " << endl;
  for (int i = 0; i < data.size(); i++) {
      cout << data[i] << " ";
  }
  cout << endl;
  
  system("pause");
  return 0;
}

