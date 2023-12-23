/*
 * @Author: zlm 
 * @Date: 2021-08-06 23:38:14 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-24 00:12:45
 */


// 堆排序是指利用堆这种数据结构所设计的一种选择排序算法。
// 堆（二叉堆）可以视为一棵完全的二叉树，除了最底层之外，每一层都是满的
// 这使得堆可以利用数组来表示，每一个结点对应数组中的一个元素。
// 二叉堆一般分为两种：最大堆和最小堆。
// 以最大堆（也叫大根堆、大顶堆）为例，其中父结点的值总是大于它的孩子节点。

// 堆排序的过程：
// 1、先把整个序列构造一个最大堆，用数组存放
// 2、把堆顶元素（最大值）和堆尾元素互换
// 3、除了堆尾，剩下的数组元素重新调整堆
// 4、重复步骤2~3，直到堆的尺寸为1

// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

/**
 * @descr: 调整堆：递归实现
 * 将序列 arr[start...end] 调整为堆结构
 * @param arr: array name
 * @param start: array index
 * @param end: array index
 */
void HeapifyRecursive(int arr[], int start, int end) {
  int left_child = 2 * start + 1;         // 左孩子索引
  int right_child = 2 * start + 2;        // 右孩子索引
  int max = start;   
  // 选出当前结点与其左右孩子三者之中的最大值
  if (left_child <= end && arr[left_child] > arr[max]) {
    max = left_child;
  }
  if (right_child <= end && arr[right_child] > arr[max]) {
    max = right_child;
  }
  if (max != start) {
    ArraySwap(arr, start, max);  // 把当前结点和它的最大(直接)子节点进行交换, 保证i节点满足堆性质
    HeapifyRecursive(arr, max, end);  // 递归调用：从当前结点向下进行堆调整
  }
}



// 调整堆: 迭代法实现
// 函数功能：将start节点及其子节点调整成堆结构，end表示最后一个节点的下标
// 调用这个函数的前提是：start节点的下一层各个节点已经满足堆的性质
void HeapifyIter(int arr[], int start, int end) {
  int temp = arr[start];
  int k = 2*start + 1;
  while (k <= end) {  // 必须是<=,否则运行出错
    if (k < end && arr[k] < arr[k+1]) {
      k += 1;   // k 指向较大的子节点
    }
    if (temp >= arr[k]) {  // 当前start节点及其子节点满足堆性质，不需要继续调整
      break;
    } else {
      // 更新根节点为最大的子节节点值
      arr[start] = arr[k];
      // start 指向下一层的父节点，下一次while时对start及其子节点调整堆
      // 新的start节点对应的值应该替换为为temp，但是考虑到start节点有可能继续向下交换
      // 所以这里不再做一次arr[start]=temp的赋值，只需要记录start本身的值即可
      // 直到最后面某个start满足堆性质并退出while循环后，再更新start节点的值接口
      start = k;
      k = 2*start + 1;
    }
  }

  arr[start] = temp; // 根元素复位 
}

// 堆排序方法-迭代方式实现
// 1、构造堆
// 2、交换首、尾元素
// 3、对前面n-1个元素进行堆的构造
// 循环执行2和3
void HeapSortIter(int arr[], int size) {
  // 构造堆
  // 从最后一个非叶子结点开始（叶结点自然不用调整）
  // 第一个非叶子结点 arr.length/2-1, 从右到左，从下至上进行调整
  for (int i = size/2 - 1; i >= 0; i--) {
    HeapifyIter(arr, i, size-1);
  }

  // 交换堆顶与数组末尾元素
  for (int j = size - 1; j >= 1; j--) {
    ArraySwap(arr, 0, j);
    HeapifyIter(arr, 0, j - 1);  // 调整前面的元素为最大堆
  }
}


// 堆排序方法-递归实现
// 1、构造堆
// 2、交换首、尾元素
// 3、对前面n-1个元素进行堆的构造
void HeapSortRecursive(int arr[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    HeapifyRecursive(arr, i, size-1);
  }

  for (int j = size - 1; j >= 1; j--){
    ArraySwap(arr, 0, j);
    HeapifyRecursive(arr, 0, j-1);
  }

}

int main() {
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };  // 从小到大堆排序
    int B[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };  // 从小到大堆排序
    int C[] = {1,10,29,3,75,22,36,0,7,23};
    int n = sizeof(A) / sizeof(int);
    HeapSortIter(A, n);
    printf("the results of HeapSortIter is: \n");
    Printer(A, n);

    HeapSortRecur(B, n);
    printf("the results of HeapSortRecur is: \n");
    Printer(B, n);

    return 0;
}