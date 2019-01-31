/**
 * 7-quicksort
 * time and space complexity: O(nlogn), O(logn)
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    while (low < high) {
        // Find the value less than pivot from the right side
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high]; // move to the left
        
        while (low < high && arr[low] < pivot) {
            low++;
        }
        arr[high] = arr[low]; // move to the right
    }

    arr[low] = pivot;
    return low;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right) {
        // partition
        int mid = partition(arr, left, right);

        // sort two subsequences
        QuickSort(arr, 0, mid-1);
        QuickSort(arr, mid+1, right);
    }
}

