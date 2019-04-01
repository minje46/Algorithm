# MCMF (Minimum Cost Maximum Flow) 

- **MCMF algorithm figures out the maximum flow with minimum cost when the graph has cost and capacity value altogether.** 

  > → Basic concept : Shortest path * flow 를 반복해서 Maximum flow를 찾는다.

  <br>

  (최소 비용 최대 유량 알고리즘은 그래프 간선에 유량과 비용이 함께 존재할 때, 최소의 비용으로 흘릴 수 있는 최대의 유량을 구하는 것이다.)

- > - Algorithm
  >
  >   1. Network flow의 모든 edge flow를 0으로 set.
  >
  >   2. Augmenting path가 있을 때 까지 3-5번을 반복한다.
  >
  >      > → Augmenting path를 더 이상 찾지 못하면 stop.
  >
  >   3. augmenting path를 search.
  >
  >      > → Residual capacity(잔여 용량)이 남은 edge들만 고려한다.
  >      >
  >      > → BFS / DFS 를 이용해서 source→set의 path를 search.
  >      >
  >      > → Augmenting path를 통해 보낼 수있는 flow의 최대량은, path의 edge들 중 최소의 residual capacity로 결정된다.
  >
  >   4. edge capacity를 compute한다.
  >
  >   5. edge flow를 increase한다. 
  >
  >      > → Edge flow 를 increase(update)할 때, 한 방향의 유량이 증가하면 다른 방향의 유량은 줄어든다. [Skew Symmetric]
  >
  >      ```c++
  >      void Ford_Fulkerson()
  >      {
  >      ```
  >

- **Example.**

  > #Step 1: Initial state.
  >
  > <img width="334" alt="MCMF_Ex)1" src="https://user-images.githubusercontent.com/23169707/55305669-63ead600-548c-11e9-9b8d-a98cbb2ec858.png">
  >
  > #Step 2 : Find a shortest path & compute cost * flow.
  >
  > <img width="342" alt="MCMF_Ex)2" src="https://user-images.githubusercontent.com/23169707/55305710-85e45880-548c-11e9-8a69-9f885c5906b8.png">
  >
  > #Step3 :  Find another shortest path until there is no more.
  >
  > <img width="336" alt="MCMF_Ex)3" src="https://user-images.githubusercontent.com/23169707/55305738-9e547300-548c-11e9-896d-23435dac1a92.png">

- **Time complexity.**

  > → f : 유량의 총 크기 / E : 간선의 개수 / V : 정점의 개수
  > $$
  > O(VEf)
  > $$
  >

- **feature.**

  > 1. **SPFA의 필요성.**
  >
  >    > → 유량의 대칭성 : f(u,v) = -f(v,u) 때문에 발생하는 backward edge가 cost에서도 영향을 줄 수 있으므로 negative value를 고려하는 shortest path algorithm을 사용해야 한다.
  >
  > 2. **Negative cycle 증명.**
  >
  >    > → Original graph에서 negative cycle이 존재하지 않는다면, backward edge를 통해서 negative cycle이 발생할 가능성은 없다.
  >    >
  >    > #1. a를 포함한 shortest path가 존재할 경우, `b>=a`가 성립하기 때문에 a가 shortest path로 선택된 것이다.
  >    >
  >    > #2. Backward edge를 통해 cost와 direction 모두 반대로 뒤집힐 경우, -a가 된다.
  >    >
  >    > #3. 이 경우, negative cycle이 발생하려면 `-a+b<0`이 성립되어야 하는데, 이는 `b<a`이기에 모순이 된다.
  >    >
  >    > > → Shortest path를 구하는 과정에서, -a를 거쳐서 b를 가는 것이 더 적은 cost이기에 선택되었을 것이라고 가정했을 때를 말한다.
  >
  > 3. **Assignment problem.**
  >
  >    > → MCMF의 대표적인 문제가 assignment problem(배정 문제)라고 할 수 있다.
  >    >
  >    > → Hungarian algorithm이 비교적 빠르게 작동하지만, 복잡성 문제로 MCMF로 접근해도 문제가 되지 않는다.

> Reference : https://koosaga.com/133

