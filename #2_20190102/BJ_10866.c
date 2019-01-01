#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *front;
	struct node *back;
}Node;

typedef struct deque
{
	int size;
	Node *head;
	Node *tail;
}Deque;

void init(Deque *deq);
int isEmpty(Deque *deq);
int retSize(Deque *deq);
int retFront(Deque *deq);
int retBack(Deque *deq);

void pushFront(Deque *deq, int data);
void pushBack(Deque *deq, int data);
int popFront(Deque *deq);
int popBack(Deque *deq);

int main()
{
	int i;
	int num, data;
	char cmd[15];
	Deque deq;
	
	init(&deq);
	
	scanf("%d", &num);
	
	for(i = 0; i < num; i++)
	{
		scanf("%s", cmd);
		if(!strcmp(cmd, "push_front"))
		{
			scanf("%d", &data);
			pushFront(&deq, data);
		}
		else if(!strcmp(cmd, "push_back"))
		{
			scanf("%d", &data);
			pushFront(&deq, data);
		}
		else if(!strcmp(cmd, "pop_front"))
		{
			printf("%d\n", popFront(&deq));
		}
		else if(!strcmp(cmd, "pop_back"))
		{
			printf("%d\n", popBack(&deq));
		}
		else if(!strcmp(cmd, "size"))
		{
			printf("%d\n", retSize(&deq));
		}
		else if(!strcmp(cmd, "empty"))
		{
			printf("%d\n", isEmpty(&deq));
		}
		else if(!strcmp(cmd, "front"))
		{
			printf("%d\n", retFront(&deq));
		}
		else if(!strcmp(cmd, "back"))
		{
			printf("%d\n", retBack(&deq));
		}
		else
		{
			printf("ERROR : invalid command\n");
		}
	}
	
	return 0;
}

void init(Deque *deq)
{
	deq->head = NULL;
	deq->tail = NULL;
	deq->size = 0;
}

int isEmpty(Deque *deq)
{
	if(deq->head == NULL)
		return 1;
	else
		return 0;
}

int retSize(Deque *deq)
{
	return deq->size;
}

int retFront(Deque *deq)
{
	if(isEmpty(deq))
		return -1;
	return deq->head->data;
}

int retBack(Deque *deq)
{
	if(isEmpty(deq))
		return -1;
	return deq->tail->data;
}

void pushFront(Deque *deq, int data)
{
	Node *nNode = (Node*)malloc(sizeof(Node));
	nNode->data = data;
	nNode->back = deq->head;
	if(isEmpty(deq))
		deq->tail = nNode;
	else
		deq->head->front = nNode;
	nNode->front = NULL;
	deq->head = nNode;
	deq->size++;
}

void pushBack(Deque *deq, int data)
{
	Node *nNode = (Node*)malloc(sizeof(Node));
	nNode->data = data;
	nNode->front = deq->tail;
	if(isEmpty(deq))
		deq->head = nNode;
	else
		deq->tail->back = nNode;
	nNode->back = NULL;
	deq->tail = nNode;
	deq->size++;
}

int popFront(Deque *deq)
{
	Node *popNode = deq->head;
	int popData;
	
	if(isEmpty(deq))
		return -1;
		
	popData = deq->head->data;
	deq->head = deq->head->back;
	deq->size--;
	free(popNode);
	
	if(deq->head == NULL)
		deq->tail = NULL;
	else
		deq->head->front = NULL;
	
	return popData;
}

int popBack(Deque *deq)
{
	Node *popNode = deq->tail;
	int popData;
	
	if(isEmpty(deq))
		return -1;
		
	popData = deq->tail->data;
	deq->tail = deq->tail->front;
	deq->size--;
	free(popNode);
	
	if(deq->tail == NULL)
		deq->head = NULL;
	else
		deq->tail->back = NULL;
	
	return popData;
}
