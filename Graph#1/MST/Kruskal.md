# MST(Minimum Spanning Tree)

- **MST is building a spanning tree with minimum cost considering each line's priority.** 

  <br>

  (MST는 간선에 가중치를 고려하여 최소 비용의 spanning tree를 선택하는 것을 말한다.)

  > - Spanning tree (신장 트리)
  >
  >   → Spanning tree는 graph의 최소 연결 부분 graph이다.
  >
  >   > - 최소 연결이라는 것은, 간선의 수가 가장 적게 graph가 이루어져 있다는 것.
  >   > - N개의 정점을 가지는 graph의 최소 간선의 수는 N-1개이고, N-1개의 간선으로 연결되어 있으면 필연적으로 Tree 형태를 이루고 있고 이것이 바로 Spanning tree 이다.

- **MST's Features.**

  > 1. 간선의 가중치의 합이 Minimum이어야 한다.
  > 2. N개의 vertex(정점)을 가지는 graph에 대해 반드시 N-1개의 간선만을 사용해야 한다.
  > 3. Cycle must not be included.

- **MST's algorithms.**

  > 1. Kruskal algorithm
  > 2. **Prim's algorighm**

------

## 1. Kruskal algorithm

- **Kruskal's algorithm is that connecting the minimum cost's line between vertexes based on greedy method.**

  <br>

  (크루스칼 알고리즘은 탐욕적인 방법을 이용하여 간선의 가중치를 최소 비용으로 연결한다. )

  > * Greedy method
  >
  >   → 각 단계에 있어서 가장 좋은 것을 선택하는 방식.

- **Kruskal's algorithm은 간선 선택을 기반으로 한다.**

  > - Algorithm
  >
  >   1. Graph의 간선들을 cost의 오름차순으로 sort한다.
  >
  >   2. Sorted 간선 list에서 순서대로 minimum cost의 간선을 선택한다.
  >
  >   3. 선택한 간선이 Cycle을 형성하는지 확인한다.
  >
  >      > **Disjoint-set algorithm을 사용한다.**
  >      >
  >      > > → Same root node를 가질 경우, cycle이라고 판단.
  >
  >   4. Cycle을 형성하지 않는 간선은 MST의 set에 추가한다.
  >
  > ![kruskal](https://user-images.githubusercontent.com/23169707/52745869-06aacc00-2f95-11e9-8869-7bdb21f19361.png)
  >
  >
  >
  > - Kruskal's code
  >
  > ```c++
  > int kruskal(int N)
  > {
  >     uf.init(kn+1);
  >     sort(e.begin(),e.end());
  >     int ret = 0;     // 간선 가중치의 합의 최솟값
  >     for(auto now: e)
  >     {
  >         if(!uf.same_set(now.v1,now.v2))	// 두 정점의 연결 여부 확인
  >         { 
  >             ret+=now.cost;       // 가중치를 ret에 더함
  >             uf.merge(now.v1,now.v2); // 두 정점 연결
  >         }
  >     }
  >     return ret;
  > }
  > ```

- **Features.**

  > → Sparse graph에서 Kruskal algorithm이 적합하다.
  >
  > > * Sparse graph : Graph 내에 적은 숫자의 간선만을 가지는 형태.
  >
  > → Dense graph에서 Prim algorithm이 적합하다.
  >
  > > * Dense graph : Graph 내에 많은 수의 간선을 가지는 형태.

- **Time complexity.**

  > → Sort에 따라 e가 달라질 수 있다.
  > $$
  > O(e logE)
  > $$
  >

- **Proof.**

  > - T = Kruskal로 선택된 간선들의 graph.
  >
  > - 귀류법 : Prim algorithm 결과가 MST가 아닐 경우.
  >
  >   > → Kruskal algorithm을 기반으로 T에 저장된 간선들은 spanning tree는 맞지만, MST은 아닐 것이다.
  >   >
  >   > → Kruskal을 시작할 때의 T를 T-init. / Kruskal 끝났을 때의 T를 T-last.
  >   >
  >   > ![image](https://user-images.githubusercontent.com/23169707/52042011-e38e1000-24f0-11e9-947f-832ca7ff3eaa.png)
  >   >
  >   > → T-init은 공집합이기 때문에 MST의 부분 그래프 였지만, T-last는 MST가 아닌 spanning tree이기 때문에 MST의 부분 그래프가 될 수 없다.
  >   >
  >   > → 따라서 Kruskal algorithm에서 T가 MST의 부분 그래프가 되는 것을 불가능하도록 만드는 간선(u,v)가 존재해야 한다.
  >   >
  >   > → 다시 말해, Kruskal algorithm에서 간선(u,v)를 제외할 경우에는 MST에 포함되어야 한다는 것이다.
  >   >
  >   > ![image](https://user-images.githubusercontent.com/23169707/52042126-38318b00-24f1-11e9-8b70-0e723b69ccfd.png)
  >   >
  >   > → 간선(u,v)를 제외한 T는 MST가 된다는 것은 기존 T의 set에서 (u,v)의 정점을 경유하도록 간선을 선택할 수 있으며, 이 경우에도 MST는 유지되어야 한다.
  >   >
  >   > → 간선(u,v)의 가중치는 T 안의 노드와 밖의 노드를 연결하는 모든 간선 중 최소 이기 때문에, 경유하지 않더라도 MST가 되어야 하기 때문에 모순이 발생한다.
  >   >
  >   > ※ Kruskal's algorithm은 MST이다.