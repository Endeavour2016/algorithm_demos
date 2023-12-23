/*
 * @Author: zlm 
 * @Date: 2018-7-26 13:44
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-24 00:24:53
 */

#include <queue>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * [RouteMatching description]
 * @param  str 
 * @param  p   
 * @return     
 */
int RouteMatching(string str, string p) {
  int len1 = str.length();
  int len2 = p.length();

  int i = 0, j = 0; // 从第一个字符开始进行比较

  while (i < len1 && j < len2) {
    if (str[i] == p[j]) {
      i++;
      j++;
    } else {
      // j从0~j，i从begin~i，间隔为j，故下一次起始字符为 i - j + 1
      i = i - j + 1; 
      j = 0;
    }
  }
  if (j == len2) // 最后一个字符已经匹配
    return i - len2;
  else 
    return -1; // 查找失败
}

//----------------kmp----------------------
/**
 * 求next数组
 * @param p    [description]
 * @param next [description]
 */
void get_next(string p, int *next) {
  if (p.size() <= 1) {  // 只有一个字符的情况
    next[0] = -1; // 初始值
    return;
  }

  // 设置初始值
  int i = 1, j = 0;
  next[0] = -1;
  next[1] = 0; // p[1]

  while (i < p.size()-1) {
  	// 若p[i] == p[i] , next[i+1] = j+1,否则 j 回溯至next[j]位置，判断p[j]=p[i]?
    if ( j == -1 || p[i] == p[j]) {
      next[i+1] = j+1; // j 为 0~next[i]-1的下一个字符，故 j= next[i]
      i++;
      j++;
    } else {
      j = next[j]; // next[j]为j位置的匹配前缀长度
    }
  }
}

int index_kmp(string str, string p) {
  int len1 = str.length();
  int len2 = p.length();
  int i = 0, j = 0;
  
  // 计算next数组
  int *next = new int[len2]; 
  get_next(p, next);

  while (i < len1 && j < len2) {
  	// j < 0表示当前字符找不到匹配的前缀，需要从0位置开始
    if (j < 0 || str[i] == p[j]) {
      i++;
      j++;
    } else {
      // i 保持不变
      j = next[j];
    }
  }
  if (j == len2) {
    return i - len2;
  } else {
    return -1;
  }
} 


int main() {
  /*
  vector<pair<int, int>> vec;
  vec.push_back(pair<int, int>(1, 2));
  vec.push_back({ 1,2 });
  */

  string str = "abadefgab";
  string p = "ade";

  int index = RouteMatching(str, p);
  int index2 = index_kmp(str, p);
  cout << "index of p in str is: " << index2 << endl;

  return 0;
}