/*
 * @Author: zlm 
 * @Date: 2021-10-23 17:04:53 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-23 17:55:15
 */

// 基本思想：
// 将所有待比较的数值统一为同样的位数，位数较短的数前面补零
// 从最低位开始，进行一次排序(具体实现是将元素分配到不同的桶中，本质上是计数排序的思想）
// 依次按照其它位进行排序, 最终序列将变成一个有序序列

// 原理：一个整数的个位、十位等可以看做是其权重因子，按照不同的权重因子
// 排完序之后，才能确定该整数的最终位置。比如日期包含年月日，对日期数据排序显然要考虑年月
// 日这个三个维度


#include <iostream>
#include <queue>
using namespace std;

const int kRadix = 10;

// 计算整数数组中元素的最大位数
int getMaxDigit(int a[], int len) {
  int max_digit_len = 1;

  for (int i = 0; i < len; i++) {  
    // 计算每一个数据的长度，取其中最大值
    int count = 1;
    int temp = a[i] / 10;
    while (temp != 0) {
      count++;
      temp /= 10;
    }
    if (max_digit_len < count) {
      max_digit_len = count;
    }
  }

  return max_digit_len;
}

void RadixSort(int a[], int length) {
    queue<int> bucket[kRadix];
    int maxDigitNum = getMaxDigit(a, length);

    // 按照数据的位数进行多次“分配、收集”
    // d从1开始，表示当前位，比如个位、十位等
    for (int r = 1, d = 1; d <= maxDigitNum; d++, r *= 10) {
        // 数据分配到对应的桶
        for (int i = 0; i < length; i++) {
          // 取出当前位的数值
          int curDigitVal = (a[i] / r) % 10;
          bucket[curDigitVal].push(a[i]);
        }

        // 数据“收集” ：本质是计数排序的过程
        // 按顺序遍历桶，将其中的数据填充到原始数组中，完成本次的排序过程 
        int k = 0;
        for (int j = 0; j < kRadix; j++) {
            while (!bucket[j].empty()) {
                // 取出队首元素，这里利用队列FIFO的特性，保证排序的稳定性
                a[k++] = bucket[j].front();  
                bucket[j].pop();
            }
        }
    }
}

int main() {
  int test[10] = { 0 };
  int len = 10;
  cout << "please input: " << endl;

  for (int i = 0; i < 10; i++)
    cin >> test[i];
  cout << endl;

  RadixSort(test,len);

  for (int i = 0;i < 10; i++)
    cout << test[i]<<" ";
  cout << endl;

  return 0;
}