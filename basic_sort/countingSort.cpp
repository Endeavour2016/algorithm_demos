/*
 * @Author: zlm 
 * @Date: 2021-10-23 15:50:11 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-23 16:38:44
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 数据结构 --------- 数组
// 最差时间复杂度 ---- O(n + k)
// 最优时间复杂度 ---- O(n + k)
// 平均时间复杂度 ---- O(n + k)
// 所需辅助空间 ------ O(n + k)
// 稳定性 ------------ 稳定(非比较型排序)


// 简单版本:
// 使用一个计数数组Cnt统计各个数字出现的次数:
// Cnt[x]的值计代表数字"x"出现的次数
// 按照顺序扫描Cnt, 将对应的数据写回原数组即可实现排序

void countingSort(vector<int> &arr) {
	int len = arr.size();
	if (len <= 1) 
		return;
	// get maximal and minimal element in vector arr
	int maxValue = *max_element(arr.begin(), arr.end());
	int minValue = *min_element(arr.begin(), arr.end());
	
	int N = maxValue - minValue + 1; // N--区间[min,max]内整数个数
	// counting array: count, len = N+1
	vector<int> cnt(N+1); // default value is 0

	// 1.count the frequency of each element
	for (int i = 0; i < len; i++) {
		cnt[arr[i]-minValue+1]++;  // cnt[1~N]--the frequency table
	}
	
	// 2.calculate the start index of each element in sorted array
	for (int r = 0; r < N; r++) {
		cnt[r+1] = cnt[r+1] + cnt[r];
	}  // cnt[x] 表示元素x+min在排序后的数组中的开始位置
	
	// 3.assign elements to temperary array tempArr
	vector<int> tempArr(len);
	for (int i = 0; i < len; i++) {
		//cnt[ arr[i]-minValue ] : start index of arr[i] in sorted array
		tempArr[cnt[arr[i]-minValue]++] = arr[i];
	}
	// 4.回写数据到原始数组
	for (int i = 0; i < len; i++)
		arr[i] = tempArr[i];
}

// 用数组作为参数
void CountingSort(int arr[], int n) {
  if (n <= 1) {
      return;
  }

  int min_val = arr[0];
  int max_val = arr[0];
  for (int i = 1; i < n; i++) {
      max_val = arr[i] > max_val ? arr[i] : max_val;
      min_val = arr[i] < min_val ? arr[i] : min_val;
  }

  int len = max_val - min_val + 1;
  int *cnt = new int[len](); // 每个元素进行0值初始化
  // int *cnt = new int[len]; 
  // memset(cnt, 0, sizeof(int)*len);
  for (int i = 0; i < n; i++) {
      cnt[arr[i] - min_val]++;
  }

  // 遍历计数数组：将数据回写至原数组
  int index  = 0;
  for (int i = 0; i < len; i++) {
      while (cnt[i] > 0) {
          arr[index++] = i + min_val;
          --cnt[i];
      }
  }
}


// 优化版：
// 统计频次后, 计算各个数据在最终排序数组中的位置;
// 扫描原始数组，将各个数据放入其对应的位置中
// 优化后该排序是稳定的！
void CountingSortImproved(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int min_val = arr[0], max_val = arr[0];
    for (int i = 1; i < n; i++) {
        max_val = arr[i] > max_val ? arr[i] : max_val;
        min_val = arr[i] < min_val ? arr[i] : min_val;
    }

    int len = max_val - min_val + 1; 
    int *cnt = new int[len](); 
    for (int i = 0; i < n; i++) {
        cnt[arr[i] - min_val]++;
    }

    // 计算各个数据在最终有序数组中的位置
    int *sorted_index = new int[len]();

    // sorted_index[x]表示数据x+min_val在最终有序数组中的起始位置
    for (int i = 1; i < len; i++) {
        sorted_index[i] = sorted_index[i-1] + cnt[i-1];
    }

    int *sorted_array = new int[n];
    for (int i = 0; i < n; i++) {
        int index = sorted_index[arr[i]-min_val];
        sorted_array[index] = arr[i];
        // +1是将后续扫描遇到的同样的元素放入到下一个位置
        ++sorted_index[arr[i]-min_val];
    }
    
    // 数据回写至原始数组
    for (int i = 0; i < n; i++) {
        arr[i] = sorted_array[i];
    }

    delete []sorted_array;
    delete []sorted_index;
    delete []cnt;
}


int main() {
    vector<int> arr = {10, 5, 9, 2, 1, 6, 2, 5, 0, 8};
    countingSort(arr);
   	for (int v : arr) 
   		cout << v << endl;
    return 0;
}


