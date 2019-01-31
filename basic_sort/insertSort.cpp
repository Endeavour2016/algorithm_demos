// 1-insert sort
// time and space complexity: O(n2), O(1)
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
