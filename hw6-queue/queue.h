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
	int  size;    //size�O��queue���̦hnode�ƶq, size �q5��
	node_t headNode;
}queue_t;


void createQueue();    //�̭��]�tinitial �� size 

int isQueueEmpty();
int isQueueFull();

int deQueue(); //�����@��node
void enQueue(int value);//�K�[�@��node
void printQueue();

void clearQueue();//�M��queue

#endif /* _T_QUEUE_H_ */