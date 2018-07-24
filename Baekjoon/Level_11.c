#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 11 - 1 (Stack)
/*
struct Node
{
	int key;
	struct Node * next;
};

void top(struct Node * top)
{
	if (top)
		printf("%d \n", top->key);
	else
		printf("%d \n", -1);
}

int empty(struct Node *top)
{
	if (top)
		printf("%d \n", 0);
	else
		printf("%d \n", 1);
}

int size(struct Node *top)
{
	int count = 0;
	
	while (top)
	{
		count++;
		top = top->next;
	}
	printf("%d \n", count);
}

struct Node *pop(struct Node *top)	// Pop call 전에 Empty 인지 먼저 확인.
{
	struct Node *prev = NULL;
	
	if (top)
	{
		printf("%d \n", top->key);
		prev = top->next;
		free(top);
		return prev; 
	}

	else
	{
		printf("%d \n", -1);
		return top;
	}
}

struct Node* push(struct Node *top ,int x)	// Push call 전에 Full 인지 먼저 확인
{
	struct Node *new = malloc(sizeof(struct Node)), *p = top;

	new->key = x;
	new->next = top;
	top = new;
	return top;
}

int main()
{
	int N, order, x, j = 0;
	char str[20], temp[10];
	struct Node *head = NULL;

	scanf("%d", &N);
	fflush(stdin);		// Baekjoon 에서 이용 불가.
	for (int i = 0; i < N; i++)
	{
		fgets(str, sizeof(str), stdin);
	
		if (strcmp(str, "pop\n") == 0)
			head = pop(head);
		else if (strcmp(str, "top\n") == 0)
			top(head);
		else if (strcmp(str, "size\n") == 0)
			size(head);
		else if (strcmp(str, "empty\n") == 0)
			empty(head);
		else
		{
			for (int i = 5; i < strlen(str); i++)
				temp[j++] = str[i];
			head = push(head, atoi(temp));
			j = 0;
		}
	}
}
*/

// 11 - 2

