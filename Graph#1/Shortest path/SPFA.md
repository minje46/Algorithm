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

## 4. SPFA(Shortest Path Faster Algorithm)

- **SPFA algorithm has developed with better performance based on bellman ford algorithm.**

  > * Graph 내부에 Negative cycle이 없어야 한다.
  >   → Shortest path를 구할 수 없다.
  > * Negative value를 가지는 edge가 있어도 된다.

  <br>

  (SPFA알고리즘은 벨만포드 알고리즘의 성능을 향상시킨 알고리즘이다. )

  > - Algorithm
  >
  >   1. Queue를 이용해서 방문할 next vertex를 저장.
  >
  >      > → Dijkstra와 다르게 vertex를 sort할 필요 X.
  >
  >   2. Shortest path 여부를 확인한다.
  >
  >      > → if(dist[dst] > dist[dpt] + cost)
  >
  >   3. Visit 여부를 확인하고, queue에 next vertex를 push.
  >
  >      > → Visit 여부를 true로 수정할 때, Cycle의 cnt도 증가시켜준다. 
  >      >
  >      > → Cycle cnt >= N 일 경우, Negative cycle 존재.
  >
  >   ```c++
  >   void SPFA()
  >   {
  >       while(!que.empty())
  >       {
  >           auto dpt = que.front();
  >           que.pop();
  >           visit[dpt] = false;
  >           
  >           for(int i=0; i<graph[dpt].size(); i++)
  >           {
  >               auto dst = graph[dpt][i].first;
  >               if(dist[dst] > dist[dpt] + graph[dpt][i].cost)
  >                   dist[dst] = dist[dpt] + graph[dpt][i].cost;
  >               if(!visit[dst])
  >               {
  >                   cycle[dst]++;
  >                   if(cycle[dst] >= N)
  >                       negative = true;
  >                   
  >                   que.push(dst);
  >                   visit[dst] = true;
  >               }
  >           }
  >       }
  >   }
  >   ```
  >
  > - Pseudo code
  >
  >   ![image](https://user-images.githubusercontent.com/23169707/54745938-3d1bdc80-4c0e-11e9-83bb-f8427ea3988e.png)

- **Time complexity.**

  > → V : 정점의 개수 / E : 간선의 개수
  > $$
  > O(VE)
  > $$
  > → 평균 Time complex
  > $$
  > O(V+E)
  > $$
  >

- **feature.**

  > 1. **Positive value and Negative value are possible.**
  >
  >    > → Dijkstra algorithm은 Positive value만 가능하다.
  >
  > 2. **In my opinion, SPFA is combination between Dijkstra and Bellman ford.**
  >
  >    > * Dijkstra algorithm 처럼, Shortest path로 update된 vertex와 connected edge만 update진행한다.
  >    >
  >    >   > → Bellman ford algorithm은 모든 vertex에서 모든 vertex에 대해 update를 진행한다.
  >    >
  >    > * Negative cycle을 확인할 수 있다.
  >    >
  >    >   > → Vertex가 N번 이상 visited될 경우, negative cycle 판단.


