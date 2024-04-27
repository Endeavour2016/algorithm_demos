#pragma once
/** 
 * 队列的链式存储及实现
 * 定义两种结构体：1.数据元素节点 2.包含队首和队尾指针的节点
 * created by zlm 2017-12-9
 */
typedef struct Node {
	int data;
	struct Node *next;
} Qnode;

// 队列首尾指针节点的定义（队列的结构，也可以添加长度等信息）
typedef struct Queue {
	Qnode *front;
	Qnode *rear;
} LinkQueue;

// 链队的操作本质上是单链表的操作，只不过限定了操作的位置

// 1. 创建空队列,不含头结点
LinkQueue *initQueue();

// 1. 带头结点的队列初始化
LinkQueue *initQueueWithHead();

// 2. enter queue,带头节点的情况
// front 指向头节点，rear 指向尾节点，元素的指向是从头节点指向尾节点
void enQueue(LinkQueue *lq, int x);

// 3. 出队
void deQueue(LinkQueue *lq, int *x);

// 4. 打印队列元素
void printQueue(LinkQueue *lq);

// 5. 求队列元素个数
int queueLength(LinkQueue *lq);
