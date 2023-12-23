/*
 * @Author: zlm 
 * @Date: 2021-10-30 21:14:04 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-30 21:15:50
 */

#include <iostream>
#include <vector>
using namespace std;

// 最差时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n)
// 在执行每一趟排序时,使用一个flag来标记是否有交换,
// 如果flag=false，则当前循环没有出现数据交换，说明此时数据已经有序了
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定

// 上升法（从底部元素开始比较，小的元素逐个上浮）
void BubbleSortUp(int a[], int length) {
  int temp = 0;
  // length-1趟
  for(int i = 0; i < length-1; i++) {
    for(int j = length-1; j >= i+1; j--) {
      if (a[j]  < a[j-1]) {
        temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
      }
    }
  }
}

// 下降法：从首元素开始向下比较, 大元素依次下降
void BubbleSortDown(int a[], int length) {
    int temp = 0;
    for (int i = length-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


// 改进：当某一趟排序后，序列已经有序，则无需再进行后面的循环
void BubbleSortImprove(vector<int> &num) {
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
        if (!flag) {
            break;
        }
    }
}

// test codes

int main() {
    srand((unsigned)time(0));
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };  // 从小到大堆排序
    int B[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };  // 从小到大堆排序
    int C[10];
    int n = sizeof(A) / sizeof(int);

    for (int i = 0; i < 10; i++) {
        C[i] = rand() % 100;
    }

    BubbleSortUp(A, n);
    printf("the results of BubbleSortUp is: \n");

    for (int i = 0; i < n; i++) {
      printf("%d ", A[i]);
    }
    printf("\n");

    BubbleSortDown(B,n);
    printf("the results of BubbleSortDown is: \n");
    for (int i = 0; i < n; i++) {
      printf("%d ", B[i]);
    }
    printf("\n");

    // BubbleSortImproved(C, 10);
    cout << "The results of BubbleSortImproved is: " << endl;
    for (auto d : C) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}

