#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
using namespace std;

/**
 * C++ implementation of single linked list 
 * @author zlm
 * @date 2017/12/8
 */

typedef struct Node {
	int data;
	Node *next;
} ListNode;

// 链表类，包含有关链表操作的成员函数
// 不带头结点
class LinkedList {
private:
	ListNode *head; 
	int size;
public:
	LinkedList();
	void insertHead(int x); // 在指针的头部插入一个值为 x 的节点,通过循环调用该函数可创建链表
	void listInsert(int pos, int data); // 在指定位置插入一个结点
	void listDelete(int data);
	int length();
	void printList();
	int findVal(int data); // 找到值为 data 的节点的位置 
	void listReverse(); // 链表反序

	~LinkedList(); // deconstructor
};

#endif // !__LINKEDLIST_H__