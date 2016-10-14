#include "queue.h"
#include <stddef.h>
#include <stdlib.h>

queue_t g_Q;

void createQueue()
{
	g_Q.front = NULL;
	g_Q.rear = NULL;
	g_Q.size = MAX_QUEUE_SIZE;
	g_Q.headNode.next = NULL;
}

int isQueueEmpty()
{
	return g_Q.headNode.next == NULL ? 1 : 0;
}

int isQueueFull()
{
	int count = 0;
	node_t *pNode;
	for (pNode = &g_Q.headNode; pNode->next != NULL; ++count, pNode = pNode->next);
	return count >= MAX_QUEUE_SIZE;
}

int deQueue()
{
	node_t *pNode = g_Q.headNode.next;
	g_Q.headNode.next = g_Q.headNode.next->next;
	free(pNode);
	return 0;
}

void enQueue(int value)
{
	node_t *pNode;
	if (isQueueFull())
		return;
	for (pNode = &g_Q.headNode; pNode->next != NULL; pNode = pNode->next);
	pNode->next = malloc(sizeof(node_t));
	pNode->next->value = value;
	pNode->next->next = NULL;
}

void printQueue()
{
	node_t *pNode;
	for (pNode = g_Q.headNode.next; pNode != NULL; pNode = pNode->next)
		printf("%d ", pNode->value);
	printf("\n");
}

void clearQueue()
{
	while (!isQueueEmpty())
		deQueue();
}
