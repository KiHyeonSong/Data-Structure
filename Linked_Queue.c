#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;

}QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkedQueueType;

void init(LinkedQueueType* s);
int empty(LinkedQueueType* s);
int full(LinkedQueueType* s);
void enqueue(LinkedQueueType* s, element item);
element dequeue(LinkedQueueType* s);
void print_queue(LinkedQueueType* q);


int main()
{
	LinkedQueueType queue;

	init(&queue);
	enqueue(&queue, 1);
	print_queue(&queue);
	enqueue(&queue, 2);
	print_queue(&queue);
	enqueue(&queue, 3);
	print_queue(&queue);

	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	return 1;
}

void init(LinkedQueueType* s)
{
	s->front = s->rear = 0;
}
int empty(LinkedQueueType* s)
{
	return (s->front == NULL);
}
int full(LinkedQueueType* s)
{
	return 0;
}
void enqueue(LinkedQueueType* s, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = item;
	temp->link = NULL;
	if (empty(s))
	{
		s->front = temp;
		s->rear = temp;
	}
	else {
		s->rear->link = temp;
		s->rear = temp;
	}

}


element dequeue(LinkedQueueType* s) {
	QueueNode* temp = s->front;
	element data;

	if (empty(s))
	{
		fprintf(stderr, "stack empty\n");
		exit(1);
	}
	else {
		data = temp->data;
		s->front = s->front->link;
		if (s->front == NULL)
			s->rear == NULL;

		free(temp);
		return data;
	}
}

void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}