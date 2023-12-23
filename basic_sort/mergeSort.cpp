/*
 * @Author: zlm 
 * @Date: 2021-08-28 23:26:45 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-30 21:27:35
 */

#include <iostream>
#include <vector>
using namespace std;


// 归并排序
// 基本思想：两个有序序列合并成一个序列

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定

// 合并两个有序序列
// 1、申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
// 2、设定两个指针，最初位置分别为两个已经排序序列的起始位置
// 3、比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
// 4、重复步骤3直到某一指针到达序列尾
// 5、将另一序列剩下的所有元素直接复制到合并序列尾

void Merge(vector<int>& vec, int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int len = right - left + 1;
  vector<int> temp;
  temp.reserve(len);

  while (i <= mid && j <= right) {
    int min_val = (vec[i] <= vec[j] ? vec[i++] : vec[j++]);
    temp.emplace_back(min_val);
  }

  // 保存剩余的元素
  while (i <= mid) {
    temp.emplace_back(vec[i++]);
  }
  while (j <= right) {
    temp.emplace_back(vec[j++]);
  }

  for (int i = 0; i <= len - 1; ++i) {
    vec[left++] = temp[i];
  }
}

// 一、归并排序-递归版本
// 把数组S分成等长度的两段S1和S2；
// MergeSort(S1), MergeSort(s2); 实现两个有序段
// Merge(s1, s2)两个有序段合并成一个有序段

void MergeSort(vector<int>& vec, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;
  MergeSort(vec, left, mid);
  MergeSort(vec, mid + 1, right);

  // 归并 vec[left...mid], vec[mid+1...right]
  Merge(vec, left, mid, right);
}


// 二、归并排序-非递归版本
// 自下而上归并：
// 1、先两两合并长度为1的序列
// 2、接着两两合并长度为2的序列
// 3、之后每次合并的序列长度为4、8、16，直到整个序列有序
void MergeSortIteration(vector<int>& vec) {
  if (vec.size() <= 1) {
    return;
  }
  int len = vec.size();

  // 从长度为1的子序列开始归并，每次归并后子序列的长度翻倍 
  for (int sub_arr_len = 1; sub_arr_len < len; sub_arr_len *= 2) {
    int left = 0;  // 从第一个子序列开始，两两合并
    while (left + sub_arr_len < len) {  // 判断是否存在相邻的子序列
      // left, left + sub_arr_len 分别为两个子序列的起始位置
      int mid = left + sub_arr_len - 1;
      int right = (mid + sub_arr_len <= len - 1) ? (mid + sub_arr_len) : len - 1;
      Merge(vec, left, mid, right);

      left = right + 1;  // 指向下一对要合并的子序列
    }
  }
}

int main(int argc, char* argv[]) {
  vector<int> vec = { 15, 20, 8, 31, 10, 19, 12, 27, 16, 21, 13, 8};
  vector<int> vec2 = { 15, 20, 8, 31, 10, 19, 12, 27, 16, 21, 13, 8};
  int n = vec.size();

  printf("before sort, vec is: \n");
  for (int i = 0; i < n; i++) {
    printf("%d\t", vec[i]);
  }
  printf("\n");

  MergeSort(vec, 0, n-1);

  printf("the sorted array is: \n");
  for (int i = 0; i < n; i++) {
    printf("%d\t", vec[i]);
  }
  printf("\n");

  MergeSortIteration(vec2);
  printf("merge sort by iteration: \n");
  for (int i = 0; i < n; i++) {
    printf("%d\t", vec2[i]);
  }
  printf("\n");

  system("pause");
}
