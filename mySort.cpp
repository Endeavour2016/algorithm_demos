/*************************************************************************
    > File Name: mySort.cpp(dell workstation, b513, 2018-5-3)
    > Author: ZLM
    > Mail: Bruce71@live.com 
    > Created Time: 2019年01月31日 星期四 10时09分38秒
 ************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * 1-insert sort
 * @param arr
 * @param len
 */
void insertSort(int arr[], int len)
{
    for (int i = 1; i < len; i++) {
        int tmp = arr[i];
        int j = i-1;
        while (j >= 0 && tmp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        // 此时tmp > arr[j], 把tmp放到arr[j]的后面
        arr[j+1] = tmp;
    }
}

/**
 * 2-bubble sort
 * time and space complexity: O(n2), O(1)
 */
void bubbleSort(vector<int> &num)
{
    int len = num.size();
    for (int i = len-1; i>= 1; i--) {
        for(int j = 0; j < i; j++) {
            if (num[j] > num[j+1]) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
    }
}

/**
 * 2-bubble sort improve
 */
void bubbleSortImprove(vector<int> &nums)
{
    int len = num.size();
    bool flag = true; 
    for (int i = len - 1; i >= 1; i--) {
        flag = false;
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j+1]) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
                flag = true;
            }
        } 
        // flag == false: no exchanges in this loop
        if (!flag) 
            break;
    }
}

/** 
 * 3-select sort
 * @param num
 */
void SelectSort(vector<int> &num)
{
    int len = num.size();
    int i,j;
    for (i = 0; i < len-1; i++) {
        int min = i;
        for (j = i+1; j < len; j++) {
            if (num[j] < num[min])
                min = j;
        }
        
        if (min != i) {
            int tmp = num[i];
            num[i] = num[min];
            num[min] = tmp;
        }
    }
}

// swap arr[i] and arr[j]
void Swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

/**
 * 4-heap sort
 * @descryption: adjust arr[s~size-1]
 * @param arr
 * @param s
 */
void heapify(int arr[], int s, int size)
{
    int left = 2*s+1;
    int right = 2*s+2;
    int max = s;

    if (left <= size-1 && arr[max] < arr[left])
        max = left;
    if (right <= size-1 && arr[max] < arr[right])
        max = right;

    if (max == s)
        return;

    // swap arr[max] and arr[s];
    int tmp = arr[max];
    arr[max] = arr[s];
    arr[s] = tmp;

    heapify(arr, max, size);
}

/** heapAjust without recursion
 * @param arr
 * @param s
 * @param len
 */
void HeapifyWithLoop(int arr[], int s, int len)
{
    int left = 2*s+1;
    int root = arr[s];
    while (left <= len-1)
    {
        if ((left+1) < len && arr[left] < arr[left+1])
            left++;
        if (arr[left] <= root) {
            break;
        }

        arr[s] = arr[left];

        // next root node and left child node
        s = left;
        left = 2*s+1;
    }
    // end for, NOW s is the last node, assign temp to arr[s]
    arr[s] = root;
}

/**
 * heap sort function
 * @param arr
 * @param len
 */
void HeapSort(int arr[], int len)
{
    if (len <= 1)
        return;

    // 1. now build a maximum heap
    for (int i = len/2-1; i >= 0; i--) {
        heapify(arr, i, len);
    }

    //2. swap the max element, push it into the tail of arr[]
    for (int j = len-1; j > 0; j--)
    {
        Swap(arr, 0, j);
        heapify(arr, 0, j);
    }

}

//------------------ 5. shell sort --------------------
void ShellSort(int arr[], int len)
{
    if (len <= 1) {
        return;
    }

    int d = len/2; // increment initial value

    while (d >= 1) {
        for (int i = d; i < len; i++) {
            int temp = arr[i];
            int j = i-d;
            for (; j >= 0 && temp < arr[j]; ) {
                arr[j+d] = arr[j];
                j -= d;
            }
            arr[j+d] = temp;
        }

        // decrease the increment
        d = d/2;
    } //end while

}

//------------------6.merge sort--------------------
// 时间复杂度：O(nlogn), 空间复杂度：O(nlogn)
/**
 * merge left and right into vec
 * @param vec
 * @param left
 * @param right
 */
void merge(vector<int> &vec, vector<int> &left, vector<int> &right)
{
    int len1 = left.size();
    int len2 = right.size();

    int i = 0, j= 0, k = 0;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }

    while (i < len1)
        vec[k++] = left[i++];

    while (j < len2)
        vec[k++] = right[j++];
}


/**
 * Merge sort
 * @param vec
 */
void MergeSort(vector<int> &vec)
{
    if (vec.size() <= 1)
        return;
    int len = vec.size();
    int mid = (len-1)/2;
    vector<int> left(vec.begin(), vec.begin() + mid + 1);
    vector<int> right(vec.begin()+mid+1, vec.end());

    MergeSort(left);
    MergeSort(right);

    merge(vec, left, right);

}

//------------------7.quicksort ---------------------
// 时间复杂度：O(nlogn), 空间复杂度：O(logn)
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high]; //小的放在左边

        while (low < high && arr[low] < pivot) {
            low++;
        }
        arr[high] = arr[low];
    }

    arr[low] = pivot;
    return low;
}

/**
 * quick sort : O(logn)
 * @param arr
 * @param len
 */
void QuickSort(int arr[], int left, int right)
{
    if (left < right) {

        // partition
        int mid = partition(arr, left, right);

        // two sub array
        QuickSort(arr, 0, mid-1);
        QuickSort(arr, mid+1, right);
    }
}

//---------------------8.RadixSort-----------------
int maxDigits(vector<int> &num)
{
    int max = 1;
    for (int i = 0; i < num.size(); i++) {
        int count = 1;
        int tmp = num[i]/10;
        while (tmp != 0)
        {
            count++;
            tmp /= 10;
        }

        if (count > max)
            max = count;
    }
    return max;
}

/** 
 * 8-radix sort
 * @param num
 */
void RadixSort(vector<int> &num)
{
    int len = num.size();
    if (len <= 1)
        return;

    int numOfDigit = maxDigits(num);
    const int radix = 10;
    // we need 10 bucket, each bucket contains a queue
    queue<int> bucket[radix];

    // d=1：表示个位，后面依次类推
    for (int d = 1, div = 1; d <= numOfDigit; d++, div *= 10) {
        // 对每个数进行分配、收集
        for (int i = 0; i < len; i++) {
            int curDigit = (num[i] / div) % 10;
            bucket[curDigit].push(num[i]);
        }

        // 收集数据
        int k = 0;
        for (int r = 0; r < radix; r++) {

            while (!bucket[r].empty()) {
                int tmp = bucket[r].front();
                num[k++] = tmp;
                bucket[r].pop();
            }
        }
    }

}

//--------------------- main function -----------------------
int main() {

    cout << "Test HeapSort!\n";
    int arr[] = {1,16,2, 18, 7, 28, 40, 11};
    int len = sizeof(arr) / sizeof(int);
    for (auto v : arr)
        cout << v << " ";
    cout << endl;

    HeapSort(arr, len);

    cout << "Heap sorted results: \n";
    for (auto v : arr)
        cout << v << " ";
    cout << endl;

    //---------------------------------------------
    cout << "Test shell sort!\n";
    int arr2[] = {1,16,2, 18, 7, 28, 40, 11};
    ShellSort(arr2, len);
    cout << "shell sorted results: \n";
    for (auto v : arr2)
        cout << v << " ";
    cout << endl;

    //---------------------------------------------
    cout << "Test merge sort!\n";
    vector<int> vec ={1,16,2, 18, 7, 28, 40, 11};
    MergeSort(vec);
    cout << "merge sorted results: \n";
    for (auto v : vec)
        cout << v << " ";
    cout << endl;

    //---------------------------------------------
    cout << "Test quick sort!\n";
    int arr3[] = {1,16,2, 18, 7, 28, 40, 11};
    QuickSort(arr3, 0, len-1);
    cout << "quick sorted results: \n";
    for (auto v : arr3)
        cout << v << " ";
    cout << endl;


    //--------------------------------------------
    cout << "Test Radix sort!\n";
    vector<int> num = {1,16,2, 18, 7, 28, 40, 11};

    RadixSort(num);
    cout << "Radix sorted results: \n";
    for (auto v : num)
        cout << v << " ";
    cout << endl;

    return 0;
}
