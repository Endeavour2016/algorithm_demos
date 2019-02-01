#include "linkedList.h"

// 构造函数
LinkedList::LinkedList() {
	size = 0;
	head = NULL;
}

// 析构函数:释放链表所占用的内存
LinkedList::~LinkedList() {
	ListNode *temp;
	for (int i = 0; i < size; i++)
	{
		temp = head;
		head = head->next;
		delete temp; // 逐个删除链表节点所占用的内存
	}
}

// 查找节点位置
// 思路：从第一个节点 head逐个查找，返回其位置
// data节点从1开始标号，head指向节点1
int LinkedList::findVal(int data) {
	ListNode *temp = head;
	int pos = 1; // 用于记录当前遍历的节点的位置
	while (temp != nullptr) {
		if (temp->data == data)
			return pos;
		
		temp = temp->next; // 开始查找下一个节点
		pos++;
	}
	return -1; // 没找到，返回-1
}

// 返回链表长度的成员函数
int LinkedList::length() {
	return size;
}

// 在头结点 head 处插入一个结点
void LinkedList::insertHead(int x) {
	ListNode *p = new ListNode;
	if (nullptr == p){
		cerr << "申请内存失败！" << endl;
		exit(-1);
	}
	p->data = x;
	p->next = head;
	head = p;

	size++; // 更新链表长度
}

// 插入一个结点(本链表是不带头结点的，即 head 指向第一个结点，结点编号为1,2,3...)
// 在 pos 处插入一个结点(插入到该节点之后) 
void LinkedList::listInsert(int pos, int data) {
    ListNode *ph = head,*pre = head;
	int i = 1;
	
	if (pos <= 0) {
		cerr << "插入位置至少从1开始！" << endl;
		exit(-1);
	}

	while (ph != nullptr && i <= pos) {
		pre = ph;
		ph = ph->next;
		i++;
	} // 结束时 pre指向第pos个结点
	
	if (nullptr == pre) {
		cout << "插入失败！" << endl;
		exit(-1);
	}

	ListNode *q = new ListNode;
	if (nullptr == q) {
		cerr << "分配内存失败！" << endl;
		exit(-1);
	}
	
	q->data = data;
	// 插入到第pos个的节点的后面：pos,q,pos+1
	q->next = pre->next;
	pre->next = q;

	size++; // 更新链表长度
}

// 删除结点
void LinkedList::listDelete(int data) {
	ListNode *pcur = head;
	ListNode *pre = head;
	if (nullptr == pcur) {
		cerr << "The linkedlist is empty!" << endl;
		exit(-1);
	}

	while ( (pcur->data != data) && pcur != nullptr) {
		pre = pcur;
		pcur = pcur->next;
	} // 跳出循环时，temp->所要删除的节点，pre指向该节点的前一个节点
	
	// ListNode *pnext = pcur->next; //先保存当前节点pcur的下一个节点的位置
	if (nullptr == pcur) {
		cerr << "没有找到需要删除的节点！" << endl;
		exit(-1);
	}

	pre->next = pcur->next;
	delete pcur;
	pcur = NULL; // 局部指针变量在函数结束后也该自动消失了吧？
	size--; // 更新链表的长度
}

// 打印链表
void LinkedList::printList() {
	if (nullptr == head) {
		cout << "The LinkList is empty!" << endl;
		return;
	}

	ListNode *p = head;
	cout << "The LinkList is as follows: " << endl;
	while (p != nullptr) {
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}

// 单链表逆置
void LinkedList::listReverse() {
	ListNode *pre, *pcur, *pnxt;
	// 如果链表为空，或者只有一个节点，则无需逆置
	if (nullptr == head || head->next == nullptr)
		return;
	
	// 当存在两个及以上的节点时，逆序才有意义
	pre = head; // 指向头节点
	pcur = head->next; // 指向当前正在逆置的节点
	while (pcur != nullptr) {
		pnxt = pcur->next; // 先保存下一个节点的位置
		pcur->next = pre; // 这一句改变了pcur所指向节点的 next 指向
		
		pre = pcur;  // 把指针 pre 和 pcur 分别向后挪动一个位置,对后面的节点执行前面的操作
		pcur = pnxt;
	}
	head->next = nullptr; // 原来的头节点现在变成了尾节点，其 next 指针应该为 nullptr
	head = pre; // 此时pre指向的为逆置后的第一个节点
}
