# Cut 

- **The definition of cut is separating graph as two groups.** 

  <br>

  (Cut은 그래프를 그래프를 양분하는 것이다.)

  > ![image](https://user-images.githubusercontent.com/23169707/55460358-c24eba80-562c-11e9-8eb8-14c26bdb90f2.png)
  >
  > → 위의 Graph를 2개의 group으로 A와 E를 분리 시킬 경우.
  >
  > <img width="429" alt="Min_cut" src="https://user-images.githubusercontent.com/23169707/55460509-1d80ad00-562d-11e9-9670-f2b92643e7ba.png">
  >
  > #Case 1. {`(b,d)`, `(c,d)`, `(c,e)`} 를 cut.
  >
  > #Case 2. {`(a,b)`, `(a,c)`} 를 cut.
  >
  > #Case 3. {`(a,c)`, `(b,c)`, `(b,d)`} 를 cut.
  >
  > → 여러 방법이 존재하지만, `case2`를 통해 2개의 edge만 cut 하면 되는 것이 minimum cut이라고 볼 수 있다.



------

# MCMF (Minimum Cut Maximum Flow) 

- **MCMF algorithm figures out the maximum flow with minimum cost when the graph has cost and capacity value altogether.** 

  > → S와 T를 cut 하는 minimum cut의 cost는 maximum flow와 동치.

  <br>

  (최소 비용 최대 유량 알고리즘은 그래프 간선에 유량과 비용이 함께 존재할 때, 최소의 비용으로 흘릴 수 있는 최대의 유량을 구하는 것이다.)

- **Example.**

  > → S와 T를 cut 하는 minimum cut의 cost는 maximum flow와 동치.
  >
  > ![image](https://user-images.githubusercontent.com/23169707/55460708-9bdd4f00-562d-11e9-8dc9-c08526b583b7.png)
  >
  > → {`(b,d)`, `(c,d)`, `(b,t)`}를 cut 하여 S와 T를 분리할 수 있고, cost : 11이다.
  >
  > ![image](https://user-images.githubusercontent.com/23169707/55460715-a26bc680-562d-11e9-8e48-1044ee0f1346.png)
  >
  > → {`S-A-B-T` = 2 / `S-A-C-B-T` = 4 / `S-C-D-T` = 3 / `S-C-B-D-T` =2} S에서 T까지 흐르는 maximum flow : 11이다.

- **Time complexity.**

  > → f : 유량의 총 크기 / E : 간선의 개수 / V : 정점의 개수
  > $$
  > O(NM + N^2logN)
  > $$
  >

- **feature.**

  > * **Max-flow, Min-cut theorem.**
  >
  >   >  <A: S→T 가능 그룹 / B : S→T 불가능 그룹.>
  >
  >   1. A에 속한 vertex u, B에 속한 vertex v에 `(u,v)`에 대해 아직 capacity가 full이지 않은 edge가 있다. 
  >
  >      > → 존재할 수 없는 가정.
  >      >
  >      > 만약 이런 edge가 존재한다면, 실제로는 cut의 cost는 흐르고 있는 flow보다 크다. 
  >      > 따라서 maximum flow와 minimum cut이 달라져야 한다.
  >      >
  >      > 왜냐하면, A에 속한 u에서 B에 속한 v로 아직 갈 수 있다는 의미이고, v는 B가 아니라 A에 속할 것이기 때문에 `모순`.
  >
  >   2. B에 속한 정점 u, A에 속한 정점 v에 대해 흐르는 flow가 0보다 큰 edge `(u,v)`가 있다.
  >
  >      > → 존재할 수 없는 가정.
  >      >
  >      > 이 경우, edge가 cut에는 포함되지 않지만, flow값에는 영향을 주게되므로 maximum flow와 minimum cut이 달라져야 한다.
  >      >
  >      > 왜냐하면, Ford fulkerson algorithm 특성상 이 경우, backward edge `(v,u)`로 유량을 보낼 수 있는 상태가 되기 때문이다. 이를 통해 backward edge를 통해 u에 도달할 수 있게 되고 u는 B가 아닌 A에 속해야 하기 때문에 `모순`. 