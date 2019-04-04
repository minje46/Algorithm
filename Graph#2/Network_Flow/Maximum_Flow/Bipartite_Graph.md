# Bipartite Graph

- **When vertexes are separated as two groups, all of vertexes in each group has edge which has different vertexes.** 

  > → 같은 그룹에 속한 정점끼리는 서로 인접하지 않는 그래프

  <br>

  (정점을 두 개의 그룹으로 나누었을 때, 존재하는 모든 간선의 양 끝 정점이 서로 다른 그룹에 속하는 형태의 그래프.)

  > ![image](https://user-images.githubusercontent.com/23169707/55456888-2b313500-5623-11e9-874a-81e0e71a18de.png)

- **All adjacent vertexes are able to be painted as two different colors.**
  <br>(인접한 정점끼리 서로 다른 색으로 칠해서, 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프.)

  > ![image](https://user-images.githubusercontent.com/23169707/55456969-7a776580-5623-11e9-9ce5-120b85773888.png)

- **Algorithm.**

  > 1. `BFS` or `DFS` search를 이용해서 vertex에 방문할 때마다 두 가지 색 중 하나를 칠한다.
  >
  > 2. 다음 vertex를 방문하면서, adjacent vertex는 자신과 다른 색으로 칠한다.
  >
  > 3. Search를 진행하면서, adjacent vertex의 색이 자신과 동일하면 `False`.
  >
  >    > → Not Bipartite graph.
  >
  > 4. Search를 완료했는데, 3번의 경우가 발생하지 않는다면 `True`.
  >
  >    > → Bipartite graph.
  >
  >    ```c++
  >    void Bipartite()
  >    {
  >        bool bipartite = true;	// Bipartite graph 확인.
  >    	for (int i = 1; i < V + 1; i++)
  >    	{
  >    		if (!bipartite)		// 이분 그래프가 아니면 반복문 탈출.
  >    			break;
  >    		
  >    		if (colors[i] == 0)	// 방문하지 않은 정점에 대해서 탐색 수행
  >    			bfs(i, RED);
  >    	}
  >    }
  >    
  >    void bfs(int root, int color) 
  >    {
  >    	queue<int> que;
  >    	queue.push(root);		// Root vertex 부터 시작.
  >    	colors[root] = color;	// Root vertex 색칠.	
  >    
  >    	while (!queue.isEmpty() && bipartite) 
  >        {	// 큐가 비어있지 않고 bipartite == ture일 때, 반복.
  >    		auto cur = que.front(); // 큐에서 정점 추출.
  >    							  
  >    		for (auto next : graph[cur]) // 해당 정점과 연결된 모든 인접 정점을 방문.
  >            {	
  >    			if (colors[adjV] == 0)	// 방문하지 않은 정점인 경우.	
  >                {
  >    				que.push(next); // 인접 정점을 큐에 삽입.
  >    				colors[next] = colors[v] * -1; // 인접한 정점을 다른 색으로 지정
  >    			}
  >                else if (colors[v] + colors[adjV] != 0)	// 색이 같은 경우.
  >                {										// Bipartite가 아니다.
  >    				checkBipartite = false;
  >    				return;
  >    			}
  >    		}
  >    	}
  >    }
  >    ```

- **Time complexity.**

  > → V : 정점 / E : 간선
  > $$
  > O(V+E)
  > $$
  >

- **Features.**

  > 1. Bipartete graph를 확인하기 위해서 `BFS` or `DFS` search를 이용.
  >
  >    > → `BFS`search 를 이용할 경우, sibling은 모두 같은 색을 가진다.
  >
  > 2. Connected component(연결 성분의 개수)를 구하는 방법과 유사.