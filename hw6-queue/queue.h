#ifndef _T_QUEUE_H_
#define _T_QUEUE_H_

#define MAX_QUEUE_SIZE 5

typedef struct  node {
	struct node *next;
	int value;
}node_t;

typedef struct {
	node_t *front;
	node_t *rear;
	int  size;    //size是指queue中最多node數量, size 訂5個
	node_t headNode;
}queue_t;


void createQueue();    //裡面包含initial 及 size 

int isQueueEmpty();
int isQueueFull();

int deQueue(); //移除一個node
void enQueue(int value);//添加一個node
void printQueue();

void clearQueue();//清空queue

#endif /* _T_QUEUE_H_ */