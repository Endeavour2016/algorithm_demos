/*
 * @Author: zlm 
 * @Date: 2021-08-06 22:21:02 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-30 21:44:26
 */

#include <iostream>
#include <vector>
#include "./common.h"

using namespace std;

// 1. 插入排序
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void InsertSort(vector<int>& vec) {
  if (vec.size() == 0) {
    return;
  }
  int len = vec.size();
  for (int i = 1; i < len; ++i) {
    // generally consider the first element as an ordered sequence
    int temp = vec[i];
    // 采用顺序查找的方法确定待插入元素在有序序列中的位置
    int j = i - 1;
    while (j >=0 && temp < vec[j]) {
      vec[j + 1] = vec[j];  // 大于temp的元素先向右移动，直到找到插入点
      j--;
    }
    vec[j + 1] = temp;
  }
}

// Binary insert sort
// 采用折半查找确定插入的下标
void BinsertSort(int a[], int n) {
  int left, right, mid;
  for (int i = 1; i < n; i++) {
    int temp = a[i];
    left = 0;
    right = i-1;
    while (left <= right) {  // 这里考虑到相邻两个数相等的情况
      mid = (left + right) / 2;
      if (temp < a[mid]) {
        right = mid - 1;
      } else {
        left = mid+1;
      }
    }

    // 最终left为待插入位置，从left开始，元素右移
    for(int j = i-1; j >= left; j--) {
      a[j+1] = a[j];
    }
    a[left] = temp;
  }
}

// 2. 希尔排序
// 希尔排序，也称递减增量排序算法，是插入排序的一种更高效的改进版本
// 插入排序在对几乎已经排好序的数据操作时效率高，即可以达到线性排序的效率
// 但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位
// 基本思想是：先将整个待排序的数据按照步长step划分成为若干子序列分别进行直接插入排序
// 待整个序列中的记录“基本有序”时，再对全体记录进行步长为1的直接插入排序

// 算法步骤:
// 1.选择一个步长序列 t1, t2, ……, tk其中 t1 > t2 > ... > tk = 1
// 2.按步长序列个数 k，对序列进行 k 趟排序
// 3.每趟排序，根据对应的步长 ti, 将待排序列分割成若干若干个子序列，划分方法：
// 序列中元素下标 index % ti = mod，相同mod的元素组成一个子序列，总共ti个子序列
// 分别对各子序列进行直接插入排序, 仅步长因为 1 时，整个序列执行一次简单插入排序即可

// 最差时间复杂度 ---- 根据步长序列的不同而不同, 最好为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

void ShellSort(vector<int> vec, vector<int> steps) {
  int step_num = steps.size();
  int len = vec.size();

  // 每个步长执行一趟插入排序
  for (int h = 0; h < step_num; h++) {
    int step = steps[h];
    // 子序列下标 [0 step 2step ...], [1 step+1 2step+1 3step+1 ...]
    // 对每个子序列进行插入排序
    for (int i = step; i < len; i++) {
      int temp = vec[i]; 
      int j = i - step;
      while (j >= 0 && temp < vec[j]) {
        vec[j + step] = vec[j];  // 每次移动指定步长
        j -= step;
      }
      vec[j + step] = temp; // temp就位
    }
  }
}


int main() {
  vector<int> nums = {5, 2, 9, 4, 7, 6, 1, 3, 8};
  InsertSort(nums);
  printf("the results of insertSort is: \n");
  Printer(nums);

  int arr[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
  int n = sizeof(arr) / sizeof(int);
  BinsertSort(arr, n);
  printf("the results of BinsertSort is: \n");
  Printer(arr, n);

  system("pause");
  return 0;
}
