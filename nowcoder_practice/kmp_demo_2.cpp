#include <iostream>
#include <string>
#include <stdlib.h>
#include <hash_map>
using namespace std;

void getNext(string p, int *next) {
  int m = p.size();
  if (m < 1)
    return;
  if (m == 1) {
    next[0] = -1;
    return;
  }
  // 下面只分析 2 个字符以上的匹配模式串
  int i = 1, j = 0; // j = next[1] = 0
  next[0] = -1;
  next[1] = 0;

  while (i < m - 1) {
    if (j < 0 || p[i] == p[j]) {  // j< 0说明p[i]没有找到前缀
      next[i + 1] = j + 1;
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
}

// kmp算法的实现
int myKMP(string str, string p) {
  if (str.empty() || p.size() > str.size())
      return -1;

  int i = 0, j = 0;
  int n = str.size(), m = p.size();

  // 获取 next 数组
  int *next = new int[m];
  getNext(p, next);

  while (i < n && j < m) {
    // j < 0表示当前字符找不到匹配的前缀，需要从0位置开始
    if (j < 0 || str[i] == p[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j == m) {
    return i - m;
  } else {
    return -1;
  }
}

int main() {
  string str = "abababb";
  string p = "ba";
  int index = myKMP(str, p);
  cout << "the pattern string is in: " << index << endl;

  system("pause");
  return 0;
}
