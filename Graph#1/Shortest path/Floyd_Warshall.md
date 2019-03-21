# Graph Shortest Path

- **Graph shortest path means the route from edge to another edge with minimum cost.** 

  <br>

  (그래프의 정점에서 또 다른 정점까지 도달하는데 최단 거리를 뜻한다.)

- **Diverse way of shortest path.**

  1. Single source and single destination shortest path problem.
     <br>(하나의 정점에서 다른 하나의 정점까지의 최단 경로를 구하는 문제.)
  2. Single source shortest path problem.
     <br>(하나의 정점에서 다른 모든 정점까지의 최단 경로를 구하는 문제)
  3. Single destination shortest path problem.
     <br>(하나의 목적지로가는 모든 최단 경로를 구하는 문제)
  4. **All pairs shortest path problem.**
     <br>(모든 최단 경로를 구하는 문제)

------

## 3. Floyd-Warshall algorithm

- **Floyd warshall algorithm figures out the shortest path of whole vertexes each other on graph.**

  > * Graph 내부에 Negative cycle이 없어야 한다. 
  >   → Shortest path를 구할 수 없다.
  > * Negative value를 가지는 edge가 있어도 된다. 

  <br>

  (플로이드-워셜 알고리즘은 그래프의 모든 정점 사이의 최단 거리를 구하는 것이다. )

  > - Algorithm
  >
  >   → i(Departure)에서 j(Destination)까지 도달할 수 있는 path를
  >
  >   i(Departure)에서 k(Stop over)까지의 path + k(Stop over)에서 j(Destination)까지의 path를 비교한다.
  >
  >   > * 점화식
  >   >
  >   >   `D[i][j] = min(D[i][j], D[i][k]+D[k][j])`
  >   >
  >   > → 점화식 기반으로 DP로 전개된다.
  >
  >   ```c++
  >   void Floyd_Warshall()
  >   {
  >      for (k = 1; k <= V; k++)		// k = 경유하는 Node.
  >       {	
  >           for (i = 1; i <= V; i++)	// i = Departure node.
  >           {
  >               for (j = 1; j <= V; j++)	// j = Destination node.
  >               {
  >                   if (dist[i][k] + dist[k][j] < dist[i][j])
  >                       dist[i][j] = dist[i][k] + dist[k][j];
  >               }
  >           }
  >       }
  >   }
  >   ```
  >
  > - Pseudo code
  >
  >   ![image](https://user-images.githubusercontent.com/23169707/54738260-d3440880-4bf6-11e9-948c-d9c86db4e58c.png)

- **Time complexity.**

  > → V : 정점의 개수 / E : 간선의 개수
  > $$
  > O(V^3)
  > $$
  >

- **feature.**

  > 1. **Positive value and Negative value are possible.**
  >
  >    > Negative cycle이 없는 경우에는 negative value도 처리해줄 수 있다.
  >    >
  >    > → Dijkstra algorithm은 Positive value만 가능하다.
  >
  > 2. **Based on Dynamic Programming.**
  >
  >    > → 출발 vertex에서 도착 vertex에 도착하기까지 k개의 vertex들을 경유할 수 있다는 개념을 DP의 점화식으로 사용.
  >    >
  >    > <img width="494" alt="Floyd_Warshall" src="https://user-images.githubusercontent.com/23169707/54738517-f0c5a200-4bf7-11e9-979f-c8a5737fe161.png">
  >    >
  >    > → Shortest path = min(i~j까지의 path, i~k까지 path + k~j까지 path)

