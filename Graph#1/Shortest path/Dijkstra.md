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

## 1. Dijkstra algorithm

- **Dijkstra algorithm is based on BFS search that it figures out the shortest path between edges with minimum cost.**

  <br>

  (다익스트라 알고리즘은 너비우선 탐색을 기본으로 하는 정점과 정점을 연결하는 경로 중 간선들의 가중치 합이 최소가 되는 최단 경로를 구하는 것이다. )

  > - Algorithm
  >
  >   1. Check되어 있지 않은 Edge 중에서 Distance가 가장 짧은 edge를 선택한다.
  >
  >   2. 선택된 Edge에서 연결된 edge와의 vertex를 통해 cost를 계산한다.
  >
  >      > Vertex(x,y,z)라고 할 경우,
  >      >
  >      > dis[y] > dis[x] + z 일 경우, update.
  >
  >   3. All edge를 check할 때 까지, 반복.
  >
  > <img width="653" alt="basic_ex" src="https://user-images.githubusercontent.com/23169707/51785986-0b592e80-2113-11e9-86e3-926401af786a.png">
  > 111-11e9-90d7-b2f4387ef501.png">

- **Example.**

- > <img width="186" alt="map" src="https://user-images.githubusercontent.com/23169707/51785996-40658100-2113-11e9-805a-6036428dd76e.png">
  >
  > Start edge : 5 [Other edges aren't connected.]
  >
  > 1. <img width="552" alt="dijkstra_1" src="https://user-images.githubusercontent.com/23169707/51786056-faf58380-2113-11e9-9712-22233d7b39eb.png">
  >    → 5번 노드의 cost는 0이고, 나머지 정점들이 가지는 최단 경로는 아직 연결이 되지 않았으므로 infinite.
  >
  > 2. <img width="553" alt="dijkstra_2" src="https://user-images.githubusercontent.com/23169707/51786091-545db280-2114-11e9-99cf-e1a6a0d4e2ec.png">
  >    → 5번 노드와 연결되어 있는 노드는 2, 4.
  >    → `dis[4] = min(dis[4], dis[5]+adj[5][2])`
  >    → min(INF, 2)
  >
  > 3. <img width="553" alt="dijkstra_3" src="https://user-images.githubusercontent.com/23169707/51786113-c0d8b180-2114-11e9-9d6b-831a4e20cd0f.png">
  >    → 나머지 edge 들 중에서 shortest edge를 선택.
  >    → 4번 노드와 연결되어 있는 노드는 3, 2.
  >
  >    → `dis[3] = min(dis[3], dis[4]+adj[4][3])`
  >
  >    → min(INF, 3)
  >
  > 4. <img width="555" alt="dijkstra_5" src="https://user-images.githubusercontent.com/23169707/51786130-2f1d7400-2115-11e9-984e-6ccd69e155f6.png">
  >
  > 5. <img width="555" alt="dijkstra_4" src="https://user-images.githubusercontent.com/23169707/51786131-2f1d7400-2115-11e9-849f-6b4ea693124d.png">
  >
  > 6. <img width="553" alt="dijkstra_6" src="https://user-images.githubusercontent.com/23169707/51786139-507e6000-2115-11e9-8fca-3d71570c66f6.png">
  >
  >    → 모든 edge를 방문할 때 까지 반복.

- **Time complexity.**

  > → Adjacent array로 표현된 Graph.
  > $$
  > O(V^2)
  > $$
  > → Adjacent list로 표현된 Graph.
  > $$
  > O(V^2+E)
  > $$
  >

- **Dijkstra algorithm feature.**

  > 1. **Vertex mush have positive value.**
  >
  >    > 최대 단점은 가중치가 *negative value* 일 경우, 작동하지 않는다.
  >    > → *Bellman-Ford algorithm*은 적용 가능.
  >
  >    ![image](https://user-images.githubusercontent.com/23169707/51786187-e74b1c80-2115-11e9-842a-e71be390099a.png)
  >
  >    > → 이전 노드까지 계산해둔 shortest path value가 shortest라고 보장할 수 없게 된다.
  >
  >    > → Dijkstra algorithm은 edge를 지날 수록 cost가 증가한다는 전제를 가지고 있다.
  >
  > 2.  **Using priority queue.**
  >
  >    > → Shortest path value의 update 횟수를 줄일 수 있다.
  >
  >    > → Dijkstar algorithm에서 performance(속도)에 영향을 주는 요소는 **Queue에서 node를 꺼내오는 횟수**와 **priority queue의 update 횟수**이다.
  >
  >    ![image](https://user-images.githubusercontent.com/23169707/51786297-16ae5900-2117-11e9-895b-fb6adb5528b8.png)
  >
  >    > * Prioirty queue.
  >    >
  >    >   → [A - C - B - E - D - E - E]
  >    >   → 이전까지 계산해둔 값이, 그 단계에서 shortest value라는 것이 보장된다.
  >    >
  >    > * Normal queue.
  >    >   → [A - B - C - E - D - E - E]
  >    >   → Random하게 선택된 edge에서 E까지 계산이 이루어지고, 최소 값의 E까지 path가 재계산과 업데이트가 필요하게 된다.



