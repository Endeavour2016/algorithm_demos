#include <iostream>
#include <vector>
using namespace std;

/**
 * simple bucket sort
 * arr: 数组里所有的元素均不超过10
 */
void simpleBucket(int arr[], int len)
{
	vector<int> cnt(11, 0); // initial value--0
	for (int i = 0; i < len; i++) {
		cnt[arr[i]]++; // 统计每个元素出现的次数
	}

	// print number appears in each bucket
	for (int i = 0; i < 11; i++) {
		for (int j = 1; j <= cnt[i]; j++) 
			cout << i << endl;
	}
}

int main() 
{
    int arr[10] = {10, 5, 9, 2, 1, 6, 2, 5, 0, 8};
    simpleBucket(arr, 10);
    return 0;
}

/* Note!
 * 以上代码仅体现了桶排序的思想，实际的桶排序要更复杂些
 * simpleBucket只是按照统计数组的下标按序输出元素值，并没有真正给原始数组排列
 */
