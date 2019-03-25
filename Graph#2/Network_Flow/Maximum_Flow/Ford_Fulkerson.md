# Maximum Flow Algorithm 

- **Maximum flow means finding the maximum flow from source to sink on graph.** 

  <br>

  (그래프위에서 source → sink 로 흐를 수 있는 최대 유량을 찾는 것.)



------

## 1. Ford Fulkerson algorithm

- **Ford fulkerson algorithm figures out the path with maximum flow from source to sink on network graph.**

  > → Basic concept : augmenting(증가하는) path를 찾으면서 flow를 증가시키는 것.

  <br>

  (포드 풀커슨 알고리즘은 네트워크 그래프에서 source→sink로 보낼 수 있는 최대 유량의 경로를 찾는 것이다.)

  > - Algorithm
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
  >      void Bellman_Ford()
  >      {
  >          // Init Single source.
  >          for(int i=1; i<=V; i++)
  >          {
  >              for(int j=1; j<=V; j++)
  >              {
  >                  for(auto idx : graph[j])
  >                  {	// RELAX Process.	
  >                  	if(dist[idx.first] > idx.second + dist[j])
  >                      {
  >                          dist[idx.first] = idx.second + dist[j];
  >      					if (i == N)	// Shouldn't be updated.				
  >      						cycle = true;		
  >                      }
  >                  }
  >              }
  >          }
  >      }
  >      ```
  >
  > - Pseudo code
  >
  >   ![image](https://user-images.githubusercontent.com/23169707/54863144-2ac5ae00-4d88-11e9-85c2-e19f39be6ace.png)

- **Example.**

  > * Augmenting path.
  >
  >   <img width="525" alt="augmenting path" src="https://user-images.githubusercontent.com/23169707/54864765-29ec4680-4d9f-11e9-9686-ff78bde14c94.png">
  >
  > * Backward edge.
  >
  >   <img width="365" alt="back edge" src="https://user-images.githubusercontent.com/23169707/54864776-425c6100-4d9f-11e9-9a66-27a163d81924.png">

- **Time complexity.**

  > → f : 유량의 총 크기 / E : 간선의 개수
  > $$
  > O(|f||E|)
  > $$
  >

- **feature.**

  > 1. **forward edge는 not full 의 성질을 이용해서 flow를 increase.**
  >
  >    > ![image](https://user-images.githubusercontent.com/23169707/54864736-c3672880-4d9e-11e9-8acb-67f48d070cd0.png)
  >
  > 2. **backward edge는 not empty 의 성질을 이용해서 decrease.**

