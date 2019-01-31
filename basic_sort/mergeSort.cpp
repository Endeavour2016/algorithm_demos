/**
 * 6-merge sort
 * time and space complexity: O(nlogn),O(nlogn)
 */
#include <iostream>
#include <vector>
using namespace std;

// merge arr[s...m], arr[m+1...e] -> tmpArr[s...e]
void merge(vector<int> &arr, vector<int> &tempArr, int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, k = startIndex, j = midIndex+1;
    while (i <= midIndex && j <= endIndex) {
        if (arr[i] <= arr[j])
            tempArr[k++] = arr[i++];
        else
            tempArr[k++] = arr[j++];
    }
    while (i <= midIndex)
        tempArr[k++] = arr[i++];
    while (j <= endIndex)
        tempArr[k++] = arr[j++];

    for (i = startIndex; i <= endIndex; i++)
        arr[i] = tempArr[i]; 
}

/**
 * Merge sort
 * @param vec
 */
void mergeSort(vector<int> &arr, vector<int> &tempArr, int s, int n)
{
    if (s < n) {
        int mid = s + (n-s)/2;
        // recusion
        mergeSort(arr, tempArr, s, mid);
        mergeSort(arr, tempArr, mid+1, n);
        merge(arr, tempArr, s, mid, n);
    }
}

// test codes
int main(int argc, char *argv[])
{
    vector<int> arr = {50, 10, 20, 30, 70, 40, 80, 60};
    int len = arr.size();
    vector<int> tempArr(len);

    int s = 0, n = len-1;
    mergeSort(arr, tempArr, s, n);
    for(int v : arr)
        cout << v << endl;
    return 0;
}