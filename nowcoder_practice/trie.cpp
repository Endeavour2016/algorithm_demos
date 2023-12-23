/*
 * @Author: zlm 
 * @Date: 2021-10-24 00:34:38 
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-24 00:38:42
 */

/**
 * Trie树，即字典树，又称单词查找树或键树，是一种树形结构，是一种哈希树的变种。
 * 典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
 * 它的优点是：最大限度地减少无谓的字符串比较，查询效率比哈希表高。
 * Trie的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。
 * 它有3个基本性质：
 * 根节点不包含字符，除根节点外每一个节点都只包含一个字符。
 * 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
 * 每个节点的所有子节点包含的字符都不相同。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

#define MAX 26
struct Trie {
    Trie *next[MAX]; // 每个节点有26个分支，对应26个字母
    int v;           //统计单词前缀出现的次数(即以该结点为结尾的单词出现的次数)
    Trie() : v(0), next{nullptr} {}
};

Trie *root = new Trie();
// 插入字符（实际上是创建字典树）
void createTrie(char *str) {
    int len = strlen(str);
    Trie *p = root, *q;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (p->next[id] == nullptr) {
            q = new Trie();
            q->v = 1; // 初始v==1

            
            /* for (int j = 0; j < MAX; ++j)
                q->next[j] = NULL; */

            p->next[id] = q;
            p = p->next[id];
        }
        else {
            p->next[id]->v++;
            p = p->next[id];
        }
    }
    p->v = -1; //若为结尾，则将 v 改成-1表示
}

int findTrie(char *str) {
    int len = strlen(str);
    Trie *p = root;
    for (int i = 0; i < len; ++i)
    {
        int id = str[i] - 'a';
        p = p->next[id];
        if (p == NULL) //若为空集，表示不存以此为前缀的串
            return 0;
        if (p->v == -1 && i == len - 1) //该字符串在“字典”中
            return 1;
    }
    return 0; //不存在
}

// 释放树所占用的内存
int dealTrie(Trie* T) {
    int i;
    if (T == NULL)
        return 0;
    for (i = 0; i < MAX; i++) {
        if (T->next[i] != NULL)
            dealTrie(T->next[i]);
    }
    delete[] T;
    return 0;
}

int main()
{
    system("pause");
    return 0;
}
