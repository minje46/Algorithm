# Graph Search

- **Graph search is searching every node** from start node to other nodes **in regular sequence.**

  <br>

  (그래프 탐색이란, 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한 번씩 방문하는 것을 말한다.)

------

## 2. DFS (Depth-First-Search)

- **DFS is searching all depth of node in branch from root node.**

  <br>

  (깊이 우선 탐색이란, 루트 노드에서 시작해서 다음 분기(branch)로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법.)

  > → Root node로부터 left의 depth의 순서로 방문하는 전체 탐색 방식이라 말할 수 있다.

  ![bfs dfs](https://user-images.githubusercontent.com/23169707/48314840-d01a8980-e612-11e8-9298-514d7405dd8b.gif)

  > * Algorithm
  >
  >   <img width="373" alt="dfs" src="https://user-images.githubusercontent.com/23169707/48315541-01975300-e61b-11e8-8d46-3cc1a6b37a01.png">
  >
  >   1. Node v를 방문한다.
  >   2. Node v에 인접한 node들 중 방문하지 않은 node가 있다면, v를 stack에 push.
  >   3. 인접한 node를 기준으로 recursive하게 1~2를 반복.
  >   4. 방문하지 않은 node가 없다면, Stack의 top을 pop.

- **Time complexity.**

  > `Number of Node(정점의 수) : N`
  >
  > `Number of Branch(간선의 수) : E`
  >
  > → Adjacent array로 표현된 Graph.
  > $$
  > O(N^2)
  > $$
  > → Adjacent list로 표현된 Graph.
  > $$
  > O(N+E)
  > $$
  >

- **DFS features.**

  > 1. **DFS is recursive algorithm.**
  > 2. DFS는 **node의 방문 여부를 반드시 check**해야 한다. (무한 loop의 위험.)
  > 3. Pre-Order Traversals을 포함한 다른 형태의 tree 순회는 모두 DFS의 종류이다.
  >
  > `Ex) 모든 node를 방문 하고자 할 때, 사용한다.`