# Graph Adjacent

- **To solve graph porblem,** **making a graph model** for problem is a common way to solve and there are two ways to make a model.

  <br>

  (그래프 관련 문제를 풀 때는, 문제 상황을 그래프로 모델링한 후에 푸는 것이 가장 보편적이고 모델링한 그래프의 연결 관계를 나타내는 두 가지 방식이 있다.)

------

## 1. Adjacen array (인접 행렬)

- **Adjacen array means making a relation with two-dimesion array.**

  <br>

  (인접 행렬은 그래프의 연결 관계를 이차원 배열로 나타내는 방식을 말한다.)

  > `adj[i][j]` : node i에서 node j로 branch가 연결되어 있다면 `1`, 연결되어 있지 않다면 `0` 으로 표현한다.
  >
  > 1. <img width="530" alt="adjacent_array 1" src="https://user-images.githubusercontent.com/23169707/48332382-f1bd5480-e696-11e8-9ea0-dddb83189f80.png">
  > 2. <img width="507" alt="adjacent_array 2" src="https://user-images.githubusercontent.com/23169707/48332367-e2d6a200-e696-11e8-80d7-bc91de21d2a8.png">
  >
  > → 2번처럼 양방향의 graph일 경우, node i에서 node j로 가는 branch가 존재한다면, j에서 i로 가는 branch 또한 존재하기 떄문에 대각성분(`adj[i][j]`에서 `i`와 `j`가 같은 원소들)을 기준으로 대칭인 성질을 갖는다.

- **Features.**

  > * Advantage 
  >
  >   1. Implementation is easy.
  >
  >   2. node i와 node j의 connection을 check할 경우, 
  >      $$
  >      O(1)
  >      $$
  >
  > * Disadvantage
  >
  >   1. Node i의 connection을 확인하기 위해, array 전체를 search해야 한다는 극단적인 문제.





------

## 2. Adjacen list (인접 리스트)

- **Adjacen list represents graph connection as vector array and vector stores the value of node.**

  <br>

  (인접 리스트는 그래프의 연결 관계를 vector로 나타내어, vector에 node value를 저장하는 방식이다.)

  > `adj[i]` : node i에 연결된 node들을 원소로 갖는 vector.
  >
  > `pair<int, int>adj[]` 를 통해 branch의 priority를 관리할 수 있다.
  >
  > 1. <img width="516" alt="adjacent_list 1" src="https://user-images.githubusercontent.com/23169707/48332811-85435500-e698-11e8-8d60-72680d49f100.png">
  > 2. <img width="532" alt="adjacent_list 2" src="https://user-images.githubusercontent.com/23169707/48332816-8d02f980-e698-11e8-9f0e-23d143cc6de1.png">
  >
  > → Node의 connection 여부를 vector array로 저장하여 표현한다.

- **Features.**

  > * Advantage
  >
  >   1. Adjacent array와 다르게, 실제로 connected node의 정보만 저장하기 때문에, vector의 element 개수의 합이 branch의 수과 같다. (Branch 개수에 비례하여 memory allocation.)
  >
  >   2. `Node의 개수 : V`, `branch 개수 : E` 라고 할 때, 
  >      Adjacent array는 각 node에 연결된 노드를 방문하기 위해 모든 node를 확인해야 한다. 
  >      $$
  >      O(V^2)
  >      $$
  >      그러나, Adjacent list는 node에 연결된 node만 확인하는 것이 가능하기 때문에, branch의 개수만큼 확인할 수 있다.
  >      $$
  >      O(E)
  >      $$
  >
  >      > Ex) Node2와 연결된 모든 node를 search 할 경우, 
  >      >
  >      > 1. Adjacent array는 `adj[2][1]`, `adj[2][2]`, `adj[2][3]`, `adj[2][4]` 를 4번 search 해야한다.
  >      > 2. Adjacent list는 `<vector>adj[2][0]` ~ `<vector>adj[2][this.size()-1]` 까지 1번 search 하면 된다.
  >
  > * Disadvantage
  >
  >   1. Node i와 Node j의 connection 여부를 check 할 경우, 
  >      $$
  >      O(V)
  >      $$
  >
  >      > Ex) Node i와 Node j의 connection 여부를 check 할 경우
  >      >
  >      > 1. Adjacent array는 `adj[i][j]` 가 `1` or `0`을 통해 확인이 가능.
  >      > 2. Adjacent list는 `<vector>adj[i][0]` ~ `<vector>adj[i][this.size()-1]` 까지 check를 해야 한다.
