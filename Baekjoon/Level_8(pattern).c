#pragma warning(disable:4996)
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

// 8 - 2
/*
int Count(int);
int main()
{
	int N;

	scanf("%d", &N);
	printf("%d \n", Count(N));
}

int Count(int num)
{
	int count = 1, min = 2, max = 7;

	if ((num <= 1000000000) && (num > 0))
	{
		if (num == 1)
			return 1;

		while (1)
		{
			if ((num >= min) && (num <= max))
				return (count+1);
			else
			{
				count++;
				min = max + 1;
				max = max + (count * 6);
			}
		}
	}
	return -1;
}
*/

// 8 - 3
/*
int main()
{
	int X, sum = 0, count = 1, order;

	scanf("%d", &X);
	while (1)
	{
		if (X == 1)
			break;
		sum += count;
		count++;
		if (sum + count >= X)
			break;
	}

	order = X - sum;

	if (count % 2 == 0)
		printf("%d/%d\n", order, (count + 1) - order);
	else
		printf("%d/%d\n", (count + 1) - order, order);
}
*/

// 8 - 4
/*
long Count(long, long);
int main()
{
	long N, x, y;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		printf("%d \n", Count(x, y));
	}
}

long Count(long a, long b)
{
	long prev = a - 1, next = a + 1, count = 0, temp = a;

	while (1)
	{
		if (temp == 0)
		{
			count += 2;
			temp++;
			continue;
		}
		if ((next == b) || (temp == b))
			return count;
		temp++;
		prev = temp - 1;
		next = temp + 1;
		count++;
	}
}
*/

// 8 - 5
/*
int Set(int, int, int);
int main()
{
	int T, N, H, W;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		printf("%d \n", Set(H, W, N));
	}
}

int Set(int height, int floor, int guest)
{
	int temp = guest, count = 1, result;

	while (1)
	{
		if (temp <= height)
			break;
		temp -= height;
		count++;
	}
	return result = temp * 100 + count;
}
*/

// 8 - 7
/*
int Member(int, int);
int main()
{
	int T, k, n;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d \n",Member(k,n));
	}
}

int Member(int a, int b)
{
	int num[14][14] = { 0, };

	for (int i = 0; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (i == 0)
				num[i][j] = j;
			else
				num[i][j] = num[i - 1][j] + num[i][j-1];
		}
	}
	return num[a][b];
}
*/

// 8 - 8
/*
int Set(char *);
int main()
{
	char N[1000000];

	fgets(N, sizeof(N), stdin);
	printf("%d \n", Set(&N));
}

int Set(char number[1000000])
{
	int arr[10] = { 0, }, max, idx;

	for (int i = 0; i < strlen(number); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (number[i] - '0' == j)
				arr[j]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			max = arr[i];
		
		if (max < arr[i])
		{
			max = arr[i];
			idx = i;
		}
	}

	if ((idx == 6) || (idx == 9))
	{
		if ((arr[6] + arr[9]) % 2 == 1)
			max = ((arr[6] + arr[9]) / 2) + 1;
		else
			max = ((arr[6] + arr[9]) / 2);
	}
	return max;
}
*/

// 8 - 9
// 처음부터 끝까지 1씩 증가시켜서 확인 시, 시간 초과. 시간 최대 : O(M*N)
/* 
int Calander(int M, int N, int x, int y)
{
	int i = 1, j = 1, count = 0;

	while ((i != M) || (j != N))
	{
		count++;

		if (i == x && j == y)
			return count;

		if (i < M)
			i++;
		else
			i = 1;

		if (j < N)
			j++;
		else
			j = 1;
	}

	if ((x == M) && (y == N))
		return count + 1;
	else
		return -1;	
}

int main()
{
	int T, M, N, x, y;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		printf("%d \n", Calander(M, N, x, y));
	}
}*/

// 공배수를 찾는 개념을 이용. 시간 최대 : O(N)  // 내 코드의 경우 loop가 2개라서 최대 O(2N)
/*
int Calander(int M, int N, int x, int y)
{
	int i = 0, j = 0, max, a = 0, b = 0;

	while (((M * a) + M) != ((N * b) + N))
	{
		if (((M * a) + M) > ((N * b) + N))
			b++;
		else
			a++;
	}

	while (((M * i) + x) != ((N * j) + y))
	{
		if (i <= a && j <= b)
		{
			if (((M * i) + x) > ((N * j) + y))
				j++;
			else
				i++;
		}
		else
			return -1;
	}

	return ((M * i) + x);
}

int main()
{
	int T, M, N, x, y;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		printf("%d \n", Calander(M, N, x, y));
	}
}*/