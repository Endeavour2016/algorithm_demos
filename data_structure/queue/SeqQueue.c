#include "queue.h"
/**
 * 顺序队列的特点：非空时，rear 指向队尾的下一个元素，front 指向队首元素
 */
// 1. 初始化操作-创建一个空队列
SeqQueue *initQueue() {
	SeqQueue *sq = (SeqQueue *)malloc(sizeof(SeqQueue));
	if (nullptr == sq) {
		printf("init failed\n");
		exit(-1);
	}
	sq->front = sq->rear = 0; // 队列初始化的状态
	return sq;
}

// 2. 入队
void enQueue(SeqQueue *sq, int data) {
	// 先判断是否已经满了
	if (sq->rear == MAXSIZE) {
		printf("The queue is full!\n");
		exit(-1); // 此函数用于退出程序，其中的参数时返回给操作系统
	}
	// 开始入队
	sq->arr[sq->rear++] = data;
}

// 3. 出队
void deQueue(SeqQueue *sq, int *x) {
	if (sq->front == sq->rear) {
		printf("Queue is empty!\n");
		return; // 结束程序 
	}
	*x = sq->arr[sq->front];
	sq->front += 1;
}

// 4.打印队列元素
void printQueue(SeqQueue *sq) {
	if (sq->front == sq->rear) {
		printf("队列为空!\n");
		return;
	}
	
	int index = sq->front;
	while (index != sq->rear) {
		printf("%d ", sq->arr[index]);
		index++;
	}
	printf("\n");
}
