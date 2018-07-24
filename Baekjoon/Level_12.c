#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//11 - 1 (Queue)		// Queue의 경우 Front 와 Rear 두 개의 변수가 main 에 return 되야하니까 전역변수로만 풀기 가능한지?
/*
struct Node
{
	int key;
	struct Node * next;
};
struct Node *head = NULL, *rear = NULL;

int front()
{
	if (head)
		return head->key;
	else
		return -1;
}

int back()
{
	if (rear)
		return rear->key;
	else
		return -1;
}

int empty()
{
	if (rear)
		return 0;
	else
		return 1;
}

int size()
{
	struct Node *p = head;
	int count = 0;

	if (!p)
		return count;

	while (p && p!=rear)
	{
		count++;
		p = p->next;
	}
	return count+1;
}


int pop()		// Pop call 전에 Empty 인지 먼저 확인.
{
	struct Node *next = NULL;
	int value;

	if (head == rear)
	{
		if (!head && !rear)
			return -1;
	
		else
		{
			value = head->key;
			head = NULL;
			rear = NULL;
			return value;
		}
	}

	else
	{
		value = head->key;
		next = head->next;
		free(head);
		head = next;
		return value;
	}
}

void push(int x)	// Push call 전에 Full 인지 먼저 확인
{
	struct Node *new = malloc(sizeof(struct Node));

	new->key = x;
	
	if (head && rear)
	{
		rear->next = new;
		rear = new;
	}
	else
	{
		head = new;
		rear = new;
	}
}

int main()
{
	int N, order, x, j = 0;
	char str[20], temp[10];

	scanf("%d", &N);
	fflush(stdin);		// Baekjoon 에서 이용 불가.
	for (int i = 0; i < N; i++)
	{
		fgets(str, sizeof(str), stdin);

		if (strcmp(str, "pop\n") == 0)
			printf("%d\n", pop());
		else if (strcmp(str, "front\n") == 0)
			printf("%d\n", front());
		else if (strcmp(str, "back\n") == 0)
			printf("%d\n", back());
		else if (strcmp(str, "size\n") == 0)
			printf("%d\n", size());
		else if (strcmp(str, "empty\n") == 0)
			printf("%d\n", empty());
		else
		{
			for (int i = 5; i < strlen(str); i++)
				temp[j++] = str[i];
			push(atoi(temp));
			j = 0;
		}
	}
}
*/
