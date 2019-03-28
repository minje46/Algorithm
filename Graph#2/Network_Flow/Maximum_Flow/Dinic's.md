# Maximum Flow Algorithm 

- **Maximum flow means finding the maximum flow from source to sink on graph.** 

  <br>

  (그래프위에서 source → sink 로 흐를 수 있는 최대 유량을 찾는 것.)



------

## 2. Dinic's algorithm

- **Dinic's algorithm figures out the path with maximum flow from source to sink on network graph.**

  > → The fastest way to get the maximum flow.
  >
  > → Basic concept : Level graph. / Blocking flow.

  <br>

  (디닉 알고리즘은 네트워크 그래프에서 source→sink로 보낼 수 있는 최대 유량의 경로를 찾는 것이다.)

  > - Algorithm
  >
  >   1. BFS를 이용해서 Level graph를 생성.
  >
  >      > → Residual capacity가 존재하는 간선만 고려해서 정점들의 level을 set. [S = level 0.]
  >      >
  >      > → T의 level이 정해지지 않는 것은 더 이상 augmenting path 없다는 것. [현재 상태가 maximum flow.]
  >
  >   2. DFS를 이용해서, level graph에 기초하고 blocking flow 규칙을 지키면서, Maximum flow 찾기.
  >
  >      > → Level + 1의 정점들만 접근하면서 T까지 DFS를 통해 이동.
  >      >
  >      > → DFS 종료 하면서, flow update. [Augmenting path가 없을 때 까지 반복.]
  >      >
  >      > → Visit array를 사용해서 불필요한 탐색을 줄인다.
  >
  >      ```c++
  >      void Dinic()
  >      {
  >      	while (bfs())		// Level graph.
  >          {
  >              fill(work, work + MAX_V, 0);
  >              while (true)
  >              {
  >                  int flow = dfs(S, INF);	// Augmenting path.
  >                  if (flow == 0)
  >                      break;
  >                  totalFlow += flow;	// Maximum flow.
  >              }
  >          }
  >      }
  >      
  >      bool bfs()
  >      {
  >      	fill(level, level + MAX_V, -1);		// Level 초기화.
  >      	level[S] = 0;	Q.push(S);
  >      	while (!Q.empty()) 
  >          {
  >      		int curr = Q.front();	Q.pop();
  >      		for (int next : adj[curr]) 
  >              {	// Resiudal capacity 확인 + level+1 증가.
  >      			if (level[next] == -1 && c[curr][next] - f[curr][next] > 0)
  >      				level[next] = level[curr] + 1;
  >      				Q.push(next);
  >      		}
  >      	}
  >      	return level[T] != -1;	// T에 도착 = True.	T에 도착X = False.
  >      }
  >      
  >      int dfs(int curr, int dest, int flow)
  >      {
  >          if (curr == dest) return flow;	// S -> T 도착.
  >      	for (int &i = work[curr]; i < adj[curr].size(); i++)
  >          {
  >      		int next = adj[curr][i];
  >      		if (level[next] == level[curr] + 1 && c[curr][next] - f[curr][next] > 0) 
  >              {	// level+1 과 capacity 확인.
  >      			int min_flow = dfs(next, dest, min(c[curr][next] - f[curr][next], flow));
  >                  
  >      			if (df > 0) 
  >                  {
  >      				f[curr][next] += min_flow;
  >      				f[next][curr] -= min_flow;
  >      				return min_flow;
  >      			}
  >      		}
  >      		return 0;	// flow = 0
  >      	}
  >      }
  >      ```
  >

- **Example.**

  > - Original example.
  >
  >   <img width="296" alt="Dinic_1" src="https://user-images.githubusercontent.com/23169707/55078971-9daf8b80-50de-11e9-87dd-6a99cdb6ca3b.png">
  >
  > - **Level graph & Blocking flow.**
  >   <img width="297" alt="Dinic_2" src="https://user-images.githubusercontent.com/23169707/55079022-b8820000-50de-11e9-8175-e59ec56447d8.png">
  >
  > - #Step1.
  >   <img width="289" alt="Dinic_EX)1" src="https://user-images.githubusercontent.com/23169707/55079194-07c83080-50df-11e9-8fb8-20a1b02068f3.png">
  >
  >   > → BFS의 level graph & DFS의 augmenting path를 통해 flow = 14.
  >
  > - #Step2.
  >
  >   <img width="587" alt="Dinic_EX)2" src="https://user-images.githubusercontent.com/23169707/55079437-84f3a580-50df-11e9-8c62-64f7982bec3e.png">
  >
  >   > → BFS의 second level graph. [Residual capacity = 0 의 edge들은 blocking flow.]
  >   >
  >   > → Backward flow(하늘색 간선)를 통해 level 3로 access는 되지만, blcoking flow.
  >   >
  >   > → DFS의 second augmenting path를 통해 flow = 5 추가.
  >
  > - #Step3.
  >   <img width="293" alt="Dinic_EX)4" src="https://user-images.githubusercontent.com/23169707/55079646-efa4e100-50df-11e9-817a-8feeeff49686.png">
  >
  >   > → BFS의 third level graph. [T를 찾을 수 없으므로 exit.]

- **Time complexity.**

  > → f : 유량의 총 크기 / E : 간선의 개수 / V : 노드의 개수
  > $$
  > O(V^2E)
  > $$
  >

- **feature.**

  > 1. **Level Graph.**
  >
  >    > → 모든 정점에 대해 Source에서 인접한 정점들을 순차적으로 level을 set한 것. 
  >    >
  >    > → Level graph에서 level+1으로만 access할 수 있다.
  >    >
  >    > → Residual capacity가 없는 edge는 사용할 수 없다.
  >
  > 2. **Blocking flow.**
  >
  >    > → Level graph에서 level+1 이외의 edge.
  >    >
  >    > → Flow를 더 이상 할 수 없는 edge.

