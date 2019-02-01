#include "LinkedQueue.h"
#include <iostream>
#include <cstdio>

// 1. 初始化（创建一个空队列）:不含头结点的版本
LinkQueue *initQueue() {
	LinkQueue *lq = (LinkQueue *)malloc(sizeof(LinkQueue));
	if (NULL == lq) {
		printf("申请内存失败!\n");
		return NULL; // 结束函数
	}

	lq->front = lq->rear = NULL;
	return lq;
}

// 1. 带头结点的队列初始化
LinkQueue *initQueueWithHead() {
	// 新建头节点
	Qnode *lh = (Qnode *)malloc(sizeof(Qnode));
	if (NULL == lh) {
		printf("申请内存失败!\n");
		return NULL; // 结束函数
	}

	lh->next = NULL;
	// 创建空队列：只包含头节点
	LinkQueue *lq = (LinkQueue *)malloc(sizeof(LinkQueue));
	if (NULL == lq) {
		printf("申请内存失败!\n");
		return NULL; // 结束函数
	}

	lq->front = lq->rear = lh;
	return lq;
}

// front 指向头节点，rear指向尾节点，元素的指向是从头节点指向尾节点
void enQueue(LinkQueue *lq, int x) {
	Qnode *p = (Qnode *)malloc(sizeof(Qnode));
	p->data = x;
	p->next = NULL;

	lq->rear->next = p;
	lq->rear = p; // 设置尾指针指向新插入的节点 p.
}

void deQueue(LinkQueue *lq, int *x) {
	// 判断是否为空队列
	if (lq->front == lq->rear) {
		printf("队列为空，无法出队！\n");
		exit(-1);
	}

	Qnode *temp = lq->front->next; //  保持要出队的节点;
	*x = temp->data;
	lq->front->next = temp->next;
	// 如果头节点后只有一个有效节点，则实际上 temp= lq->rear; 
	// 此时为防止丢失rear指针，应执行以下操作
	if (temp == lq->rear)
		lq->rear = lq->front; // 此时让尾指针指向头节点

	free(temp);
	temp = NULL;
}

void printQueue(LinkQueue *lq) {
	Qnode *p = lq->front->next; // 第一个元素
	if (!p) {
		printf("队列为空");
		return;
	}
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int queueLength(LinkQueue *lq) {
	Qnode *p = lq->front->next; // p指向第一个节点

	int count = 0;
	while (p) {
		count += 1;
		p = p->next;
	}
	return count;
}
