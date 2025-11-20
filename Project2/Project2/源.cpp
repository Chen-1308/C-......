//头文件区 
#include<stdlib.h>
#include"stdio.h"
#include"math.h"
#include"Windows.h"
//队列定义
struct Node
{
	int data;
	struct Node* next;
};
struct QueueLinklist
{
	struct Node* Head;
	struct Node* Tail;
};
//队列是否已满 ,不管 
//队列是否为空 
int IsEmpty(struct QueueLinklist queue)
{
	int is_empty = 0;
	if (queue.Head == NULL)
	{
		is_empty = 1;
	}
	return is_empty;
}
//入队
struct Node* CreateNode(int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = value;
	(*newNode).next = NULL;
	return newNode;
}
void Initqueue(struct QueueLinklist* queue)
{
	queue->Head = NULL;
	queue->Tail = NULL;
}
void Enqueue(struct QueueLinklist* queue, int value)
{
	struct Node* newNode = CreateNode(value);
	if (queue->Head != NULL)
	{
		(queue->Tail)->next = newNode;
		queue->Tail = newNode;
	}
	else
	{
		queue->Head = newNode;
		queue->Tail = newNode;
	}

}
//出队
int Dequeue(struct QueueLinklist* queue)
{
	if (queue->Head != NULL)

	{
		int item = (queue->Head)->data;
		struct Node* temp = queue->Head;
		queue->Head = (queue->Head)->next;
		if (queue->Head == NULL)
		{
			queue->Tail == NULL;
		}
	//	free(temp);
		return item;
	}
	else
	{
		printf("队列为空\n");
		return -1;
	}
}

//对列打印函数 

//主函数 
void PrintQueueList(struct QueueLinklist* queue)
{
	struct Node* ptr = queue->Head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
int main()
{
	/*
	struct QueueLinklist queue;
	Initqueue(&queue);
	PrintQueueList(&queue);
	*/
	
	struct QueueLinklist *queue=NULL;
	queue = (struct QueueLinklist*)malloc(sizeof(struct QueueLinklist));
	Initqueue(queue);
	PrintQueueList(queue);
	for (int i = 0; i < 50; i++)
	{
		Enqueue(queue, i);
	}
	PrintQueueList(queue);

	for (int i = 0; i < 25; i++)
	{
		Dequeue(queue);
	}
	PrintQueueList(queue);
	return 0;
}