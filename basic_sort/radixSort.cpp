/**
 * 8-quicksort
 * time and space complexity: O(nk), O(n+k)
 * k: radix
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// return the maximum of digital bits
int maxDigits(vector<int> &num) {
	int max = 1;
	int len = num.size();
	// calculate the length of each element
	for (int i = 0; i < len; i++) {
		int curLen = 1;
		int temp = num[i]/10;
		while (temp != 0) {
			++curLen;
			temp /= 10;
		}

		if (max < curLen)
			max = curLen;
	}
	return max;
}

void radixSort(vector<int> &num) {
	int len = num.size();
	if (len <= 1)
		return;

	const int radix = 10; 
	int numOfDigitBits = maxDigits(num);

	// distribute the elements to different buckets
	queue<int> buckets[radix];

	// sort by single digit, ten digit,...
	for (int d = 0, div = 1; d < numOfDigitBits; d++, div *= 10) {
		// distribute each elments
		for (int i = 0; i < len; i++) {
			int curDigit = (num[i] / div) % 10;
			buckets[curDigit].push(num[i]);
		}

		// collect elements
		int k = 0;
		for (int r = 0; r < radix; r++) {
			while (!buckets[r].empty()) {
				int tmp = buckets[r].front();
				num[k++] = tmp;
				buckets[r].pop() 
			}
		}
	}
}

