 
// 3-select sort
// time and space complexity: O(n2), O(1)
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