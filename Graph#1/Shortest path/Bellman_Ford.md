# Graph Shortest Path

- **Graph shortest path means the route from edge to another edge with minimum cost.** 

  <br>

  (그래프의 정점에서 또 다른 정점까지 도달하는데 최단 거리를 뜻한다.)

- **Diverse way of shortest path.**

  1. Single source and single destination shortest path problem.
     <br>(하나의 정점에서 다른 하나의 정점까지의 최단 경로를 구하는 문제.)
  2. **Single source shortest path problem.**
     <br>(하나의 정점에서 다른 모든 정점까지의 최단 경로를 구하는 문제)
  3. Single destination shortest path problem.
     <br>(하나의 목적지로가는 모든 최단 경로를 구하는 문제)
  4. All pairs shortest path problem.
     <br>(모든 최단 경로를 구하는 문제)

------

## 2. Bellman-Ford algorithm

- **Bellman ford algorithm is figuring out the shortest path on graph which has even negative value.**

  <br>

  (벨만포드 알고리즘은 음수 가중치가 있는 그래프에서도 정점과 정점을 연결하는 경로 중 간선들의 가중치 합이 최소가 되는 최단 경로를 구할 수 있다. )

  > - Algorithm
  >
  >   1. Shortes path를 찾기 위해 RELAX을 M번 반복.
  >
  >      > M = 정점의 개수 - 1 (모든 간선 순회)
  >      >
  >      > → 모든 정점은 M번의 간선을 통해 도달할 수 있다는 개념을 이용.
  >
  >   2. Negative cycle을 판단하기 위해 반복.
  >
  >      > N = 정점의 개수 (모든 간선 + 1)
  >      >
  >      > → N번째에 shortest path가 update될 경우, negative cycle이 존재하는 것.
  >
  >      ```c++
  >      void Bellman_Ford()
  >      {
  >          // Init Single source.
  >          for(int i=1; i<=V; i++)
  >          {
  >              for(int j=1; j<=V; j++)
  >              {
  >                  for(auto idx : graph[j])
  >                  {	// RELAX Process.	
  >                  	if(dist[idx.first] > idx.second + dist[j])
  >                      {
  >                          dist[idx.first] = idx.second + dist[j];
  >      					if (i == N)	// Shouldn't be updated.				
  >      						cycle = true;		
  >                      }
  >                  }
  >              }
  >          }
  >      }
  >      ```
  >
  > * Pseudo code
  >
  >   ![image](https://user-images.githubusercontent.com/23169707/54694484-a4cd1b80-4b6b-11e9-949e-284063f91501.png)

- **Time complexity.**

  > → V : 정점의 개수 / E : 간선의 개수
  > $$
  > O(|V||E|)
  > $$

- **feature.**

  > 1. **Positive value and Negative value are possible.**
  >
  >    > Negative value가 있는 graph에서 shortest path를 구할 수있다.
  >    > → Dijkstra algorithm은 Positive value만 가능하다.
  >
  > 2. **Figure out negative cycle on graph.**
  >
  >    > Negative cycle(음수 사이클)의 존재 여부를 파악할 수 있다.
  >

