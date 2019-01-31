/**
 * 4-heap sort--maximum heap
 * adjust arr[s~size-1]--recusion version
 * @param arr: array name
 * @param size: array length
 * @param s: index
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

// implementation with loop
void HeapifyWithLoop(int arr[], int s, int len)
{
    int left = 2*s + 1;
    int root = arr[s];
    while (left <= len-1) {
        if ((left+1) < len && arr[left] < arr[left+1])
            left++; // determine the max between arr[left], arr[right]
        if (arr[left] <= root) {
            break;
        }

        arr[s] = arr[left];

        // next root node and left child node
        s = left;
        left = 2*s+1;
    }
    // here, s is the last node, then assign root to arr[s]
    arr[s] = root;
}

// Heap sort main function
void heapSort(int arr[], int len)
{
    if (len <= 1)
        return;

    // build a maximum heap: arr[0~len-1]
    for (int i = len/2-1; i >= 0; i--) {
        heapify(arr, i, len);
    }

    // put the max element into the tail of arr
    for (int j = len-1; j > 0; j--)
    {
        Swap(arr, 0, j);
        heapify(arr, 0, j);
    }

}

// swap arr[i] and arr[j]
void Swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}