// 5-shell sort
// A improved version of direct-insertion sort
void shellSort(int arr[], int len)
{
    if (len <= 1)
        return;
    
    // initialize the increment
    int d = len/2; 
    while (d >= 1) {
        for (int i = d; i < len; i++) {
            int temp = arr[i];
            int j = i-d;
            // while (j >= 0 && temp < arr[j])
            for (; j >= 0 && temp < arr[j]; ) {
                arr[j+d] = arr[j];
                j -= d;
            }
            arr[j+d] = temp;
        }

        // decrease the increment
        d = d / 2;
    } //end while
}
