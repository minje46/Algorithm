# Segment Tree

- **Segment tree is replying the answer fast based on processed data.**

  <br>(세그먼트 트리는 저장된 자료들을 적절히 전처리하여 질의에 빠르게 대답할 수 있도록 하는 것이다.)

- **It is efficient to get the answer between intervals.**

  <br>(구간에 대한 질문에 효율적으로 대답하는 것이다.)

- **Node of tree has interval data.**

  <br>(트리의 노드에 구간 정보를 저장하고 있다.)

> - Algorithm
>
>   1. Set tree size(height)
>      ![image](https://user-images.githubusercontent.com/23169707/51383690-fc4cfd80-1ace-11e9-92c0-241e9c2fd5f2.png)
>
>   2. Build a tree(value in node)
>
>   3. Search the interval.
>
>      * Divide and search.
>
>        > [start, end] 범위가 [left, right]범위와 부분적으로 겹치는 경우.
>
>      * return value.
>
>        > 1. [left, right] 범위가 [start, end]와 전혀 겹치지 않는 경우
>        > 2. [left, right] 범위가 [start, end]에 완전히 포함되어 있는 경우
>        > 3. [start, end] 범위가 [left, right]에 완전히 포함되어 있는 경우
>
> - Psuedo-code
>
>   ```c++
>   // 세그 트리 크기를 구한다.
>   int h = (int)(ceil(log2(n)) + 1e-9);
>   int tree_size = (1 << (h + 1));
>   
>   // 세그 트리 형성.
>   vector<int> tree(tree_size);
>   init(arr, tree, 1, 0, n - 1);
>   
>   void init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
>   {
>   	// start와 end가 같으면 리프 노드. 이때 node에 start idx를 넣는다.
>   	if (start == end)
>   		tree[node] = start;
>   
>   	// start와 end가 다르다면
>   	else
>   	{
>   		int mid = (start + end) / 2;
>   		init(arr, tree, node * 2, start, mid);
>   		init(arr, tree, node * 2 + 1, mid + 1, end);
>   
>   		// 각 구간에서 가장 높이가 낮은 것을 노드에 넣어준다.
>   		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
>   			tree[node] = tree[node * 2];
>   		else
>   			tree[node] = tree[node * 2 + 1];
>   	}
>   }
>   ```

- **Time complexity.**

  > $$
  > O(logN)
  > $$
  >