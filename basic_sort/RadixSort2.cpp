/*
* @Author: zlm 
* @Date: 2021-10-23 17:03:09 
* @Last Modified by: zlm
* @Last Modified time: 2021-10-30 21:17:27
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

typedef int T;

// 取出第 d 位上的数值
// d取1,2,3..., d = 1 表示第1位，依次类推
T GetDigit(T num, size_t d) {
  // pow返回值是double型，把它赋给num后会自动转换成整型
  num = num / pow(10, d - 1);
  return num % 10;
}

// 找到数组中最大的元素,len 为数组长度
T FindMax(T a[], size_t len) {
  T max = a[0];
  for (size_t i = 1; i < len; i++) {
    if (max < a[i])
      max = a[i];
  }
  return max;
}

// 计算数据的位数
size_t DigitNumber(T num) {
  size_t count = 1;
  T temp = num / 10;
  while (temp != 0) {
    count++;
    temp /= 10;
  }

  return count;
}

void RadixSort(T a[], size_t length) {
  const size_t radix = 10;   // 0~9号桶，基数为10
  size_t count[radix] = { 0 }; // 用一个数组统计各个桶里分配的元素的个数，初始时应全为 0；

  T maxVal = FindMax(a, length);
  size_t maxDigit = DigitNumber(maxVal); 

  for (size_t d = 1; d <= maxDigit; d++) {
    // 用于收集每一次分配后的数据元素(此时每个元素都不会被初始化)
    T *bucket = new T[length]();
    
    // 每次分配桶之前，先清零
    for (size_t i = 0; i < radix; i++) {
      count[i] = 0;
    }

    // 统计桶中的数字个数
    for (size_t j = 0; j < length; j++) {
      T digit = GetDigit(a[j], d);
      count[digit] ++;
    }

    // 记录各个桶中最后一个元素的下标索引
    for (size_t j = 1; j < radix; j++) {
      count[j] = count[j] + count[j - 1];
    }

    // 开始收集分配后的这些数据, 存放到数组 bucket中
    // j>=0不能使用 size_t 类型，否则陷入死循环
    for (int j = length - 1; j >= 0; j--) {
      T digit = GetDigit(a[j], d);     // 找当前元素所属的桶
      size_t index = count[digit] - 1; // 把每个元素a[i]存放在 bucket 中正确的位置。

      bucket[index] = a[j];
      count[digit]--; // 把相同桶的元素存放在上一个元素的前面
    }

    // 此时,按照 d 位的排序已完成，存放在 bucket中，现在将其复制到原数组 a 中
    for (size_t j = 0; j < length; j++) {
      a[j] = bucket[j];
    }
    delete []bucket;
  }
}

int main() {
  T A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };  // 从小到大堆排序

  size_t n = sizeof(A) / sizeof(int);
  RadixSort(A, n);
  printf("the results of RadixSort is: \n");
  for (size_t i = 0; i < n; i++) {
      printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
