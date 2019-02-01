#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

// sequential queue structure definition
typedef struct Queue {
	int arr[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

// 1. 初始化操作
SeqQueue *initQueue();

// 2. 入队
void enQueue(SeqQueue *sq, int data);


// 3. 出队
void deQueue(SeqQueue *sq, int *x);

// 4.打印队列元素
void printQueue(SeqQueue *sq);
