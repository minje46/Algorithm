# DAG (Directed Acyclic Graph)

- **DAG is the directed graph without cycle.**
  <br>(DAG는 사이클이 없는 방향 그래프를 말한다.)

  <img width="323" alt="DAG" src="https://user-images.githubusercontent.com/23169707/54104904-c49a6c00-4414-11e9-8252-c1cdc2724d15.png">

------

## Topological Sort

- **It is the algorithm to figure out the order of task.**<br>

  (어떤 일을 하는 순서를 찾는 알고리즘이다.)

  > <img width="412" alt="topological_2" src="https://user-images.githubusercontent.com/23169707/54105878-be59bf00-4417-11e9-9d72-f47429371bb9.png">

- **It makes order of each edges in directed graph based on pre-defined order.** <br>(방향 그래프에 존재하는 각 정점들의 선행 순서를 위배하지 않으면서 모든 정점을 나열하는 것.)

  > * Algorithm - [Indegree(진입차수)]
  >
  >   1. 진입 차수가 0인 edge(=들어오는 간선의 수가 0)를 선택한다.
  >
  >      * 진입 차수가 0인 edge가 여러 개일 경우, random하게 선택해도 된다.
  >      * Indegree가 0인 edge들을 queue에 모두 push한다.
  >
  >   2. 선택된 edge와 연결된 모든 간선을 delete한다.
  >
  >      - 선택된 edge를 queue에서 delete.
  >      - 선택된 edge에 연결된 간선에 대한 수를 decrease.
  >
  >   3. 위의 과정을 반복해서 모든 edge들을 선택, 삭제되면 완료.
  >
  >      <img width="411" alt="Topological" src="https://user-images.githubusercontent.com/23169707/54105666-0e845180-4417-11e9-9e1f-f25289e9f035.png">
  >
  > * Algorithm -  [DFS]
  >
  >   - DFS의 result를 stack에 push하고 pop하면 topological sort가 된다.
  >
  >   <img width="711" alt="topological_dfs" src="https://user-images.githubusercontent.com/23169707/54106313-0b8a6080-4419-11e9-98e8-f0f354fbecd1.png">
  >
  >   1. step#1 : 1→2→5→7
  >   2. step#2 : 3→6
  >   3. step#3 : 4
  >
  >   - Result : 1→2→5→7→3→6→4



- **Time complexity.**

  > → Indegree가 0인 node를 search하는 과정 (DFS 1번)
  >
  > → Indegree를 조정해가면서 search하는 과정 (DFS 2번)
  >
  > → DFS를 2번한 시간이 소요.
  > $$
  > O(|V| + |E|)
  > $$
  >

- **Topological sort feature.**

  > 1. 하나의 directed graph에서 여러가지 topological sort가 가능하다.
  > 2. Topological sort의 과정에서 선택되는 edges들의 order를 topological sort라고 한다.
  > 3. Topological sort의 과정에서 graph에 남아 있는 edges 중에 indegree(진입 차수)가 0인 edge가 없다면, topological sort가 불가능한 graph라고 판단된다.
  >



