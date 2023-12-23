/*
 * @Author: zlm 
 * @Date: 2021-10-24 00:02:42 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-24 00:03:30
 */

// 选择排序
// 稳定性：不稳定
// 复杂度: O(n^2)
// 算法思路：
// 第一趟排序，从n个元素中选择最小值放置在a[0];
// 第二趟排序，从n-1个元素中选择最小值放置在a[1];
// 第k趟排序，从n-k+1个元素中选择最小值放置在a[k-1]处
#include <iostream>
#include <vector>
using namespace std;

void SelectSort(int a[], int length) {
    int min;
    for (int i = 0; i < length - 1; ++i) {
        min = i;
        for (int j = i + 1; j < length; j++) {
            min = a[j] < a[min] ? j : min;
        }
        if (min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

// 每次选择最大值放置在数组后面
void SelectSort2(int a[], int length) {
    int max;
    for (int i = length - 1; i > 0; i--) {
        max = 0; // 每次从数组a[0]开始比较，把最大的元素向后转移
        for (int j = 1; j <= i; j++) {
            max = a[j] > a[max] ? j : max;
        }
        if (max != i) {
            int temp = a[max];
            a[max] = a[i];
            a[i] = temp;
        }
    }
}


int main() {
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
    int B[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
    
    int n = sizeof(A) / sizeof(int);
    SelectSort(A, n);
    printf("the results of SelectSort is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    SelectSort2(B,n);
    printf("the results of SelectSort2 is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;
}



