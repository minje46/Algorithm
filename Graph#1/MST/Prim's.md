# MST(Minimum Spanning Tree)

- **MST is building a spanning tree with minimum cost considering each line's priority.** 

  <br>

  (MST는 간선에 가중치를 고려하여 최소 비용의 spanning tree를 선택하는 것을 말한다.)

  > * Spanning tree (신장 트리)
  >
  >   → Spanning tree는 graph의 최소 연결 부분 graph이다.
  >
  >   > * 최소 연결이라는 것은, 간선의 수가 가장 적게 graph가 이루어져 있다는 것.
  >   >
  >   > * N개의 정점을 가지는 graph의 최소 간선의 수는 N-1개이고, N-1개의 간선으로 연결되어 있으면 필연적으로 Tree 형태를 이루고 있고 이것이 바로 Spanning tree 이다.

- **MST's Features.**

  > 1. 간선의 가중치의 합이 Minimum이어야 한다.
  > 2. N개의 vertex(정점)을 가지는 graph에 대해 반드시 N-1개의 간선만을 사용해야 한다.
  > 3. Cycle must not be included.

- **MST's algorithms.**

  > 1. Kruskal algorithm
  > 2. **Prim's algorighm**

------

## 2. Prim's algorithm

- **Prim's algorithm is extending graph based on start poing step by step.**

  <br>

  (프림 알고리즘은 시작 정점에서부터 출발하여 단계적으로 확장해나가는 방법이다. )

- **Prim's algorithm은 정점 선택을 기반으로 한다.**

  > - Algorithm
  >
  >   1. Start 단계에서는 start point만이 MST set에 포함된다.
  >   2. MST set에 adjacent node들 중에서 minimum cost의 line(간선)으로 connected 된 node를 선택해서 extend한다.
  >   3. Tree가 N-1개의 간선을 가질 때까지 반복한다.
  >
  > <img width="270" alt="prim" src="https://user-images.githubusercontent.com/23169707/52040795-5dbc9580-24ed-11e9-8f2f-c3492791bb31.png">
  >
  > * Pseudo - code
  >
  > ![image](https://user-images.githubusercontent.com/23169707/52041764-32877580-24f0-11e9-9ff9-c4b974c59750.png)
  >
  >

- **Time complexity.**

  > → Normal queue를 이용.
  > $$
  > O(V^2)
  > $$
  > → Minimum priority queue를 이용.
  > $$
  > O(ElogV)
  > $$
  >

- **Proof.**

  > * T = Prim으로 선택된 간선들의 graph.
  >
  > * 귀류법 : Prim algorithm 결과가 MST가 아닐 경우.
  >
  >   > → Prim algorithm을 기반으로 T에 저장된 간선들은 spanning tree는 맞지만, MST은 아닐 것이다.
  >   >
  >   > → Prim을 시작할 때의 T를 T-init. / Prim 끝났을 때의 T를 T-last.
  >   >
  >   > ![image](https://user-images.githubusercontent.com/23169707/52042011-e38e1000-24f0-11e9-947f-832ca7ff3eaa.png)
  >   >
  >   > → T-init은 공집합이기 때문에 MST의 부분 그래프 였지만, T-last는 MST가 아닌 spanning tree이기 때문에 MST의 부분 그래프가 될 수 없다.
  >   >
  >   > → 따라서 Prim algorithm에서 T가 MST의 부분 그래프가 되는 것을 불가능하도록 만드는 간선(u,v)가 존재해야 한다.
  >   >
  >   > → 다시 말해, Prim algorithm에서 간선(u,v)를 제외할 경우에는 MST에 포함되어야 한다는 것이다.
  >   >
  >   > ![image](https://user-images.githubusercontent.com/23169707/52042126-38318b00-24f1-11e9-8b70-0e723b69ccfd.png)
  >   >
  >   > → 간선(u,v)를 제외한 T는 MST가 된다는 것은 기존 T의 set에서 (u,v)의 정점을 경유하도록 간선을 선택할 수 있으며, 이 경우에도 MST는 유지되어야 한다.
  >   >
  >   > → 간선(u,v)의 가중치는 T 안의 노드와 밖의 노드를 연결하는 모든 간선 중 최소 이기 때문에, 경유하지 않더라도 MST가 되어야 하기 때문에 모순이 발생한다.
  >   >
  >   > ※ Prim's algorithm은 MST이다.
