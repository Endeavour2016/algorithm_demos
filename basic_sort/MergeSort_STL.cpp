/*
 * @Author: zlm 
 * @Date: 2021-10-30 21:17:49 
 * @Last Modified by:   zlm 
 * @Last Modified time: 2021-10-30 21:17:49 
 */

#include <iostream>
#include <vector>
using namespace std;


void Merge(vector<int> &v, vector<int> &left, vector<int> &right) {
  int i=0, j=0, k=0;
  while(i < left.size() && j < right.size())
  {
    if (left[i] <= right[j])
      v[k++] = left[i++];
    else
      v[k++] = right[j++];
  }

  while (i < left.size())
    v[k++] = left[i++];
  while (j < right.size())
    v[k++] = right[j++];
}

void MergeSort(vector<int> &v) {
    int len = v.size();
    if (len <= 1)
      return;  // 只有一个元素，不需要排序

    // 1.分成两个子序列，递归排序
    int mid = len / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin()+mid, v.end()); 

    MergeSort(left);
    MergeSort(right);

    // 2.合并有序序列
    Merge(v, left, right);
}

int main() {
    vector<int> v;
    int data = 0;
    while(cin >> data) {
      v.push_back(data);
    }

    cout <<"result is: \n";

    MergeSort(v);

    for (auto x : v)
      cout << x <<" ";

    cout << endl;

    return 0;
}