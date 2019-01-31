#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/** 
 * 10-counting sort
 * time complexity: 
 * space complexity:
 */

void countingSort(vector<int> &arr)
{
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
	} // cnt[x] 表示元素x+min在排序后的数组中的开始位置
	
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

int main() 
{
    vector<int> arr = {10, 5, 9, 2, 1, 6, 2, 5, 0, 8};
    countingSort(arr);
   	for (int v : arr) 
   		cout << v << endl;
    return 0;
}


