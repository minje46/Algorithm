# Bipartite Matching 

- **Bipartite matching is making the connection between each vertex on bipartite graph.** 

  > ![image](https://user-images.githubusercontent.com/23169707/55458056-d2fc3200-5626-11e9-9b64-f0935e7d4494.png)

  <br>

  (이분 매칭이란, 이분 그래프의 각 정점이 다른 정점 하나만을 연결하고 있는 그래프.)

- > - Algorithm
  >
  >   1. Bipartite graph의 gropu A의 모든 vertex를 연결한다.
  >
  >   2. `DFS` search를 통해 방문 여부와 함께 matching 가능 여부를 확인.
  >
  >      > → Vertex가 matching 되었는지 check.
  >      >
  >      > → 이미 matching된 vertex가 다른 connection 가능한지 DFS를 통해 재확인.
  >
  >   3. `Ture` 와 `False`를 통해 Bipartite matching을 확인.
  >
  >      ```c++
  >      void Bipartite()
  >      {
  >          int result = 0;
  >          for (int i = 1; i <= n; i++) // 모든 정점.
  >          {
  >              memset(visited, 0, sizeof(visited));
  >              if (dfs(i))
  >                  result++;
  >          }    
  >          return result;
  >      }
  >      
  >      int dfs(int cur) 
  >      {
  >          if (visited[cur]) //방문 된 정점은 매칭 불가. 
  >              return 0;    
  >          visited[cur] = 1;
  >          
  >          for (auto next = graph[cur])
  >          {	// 아직 매칭X.
  >              if (!bip[next] || dfs(bip[next])) 
  >              { //이미 매칭된 정점이 다른 매칭 가능할 때.
  >                  bip[next] = cur; // 정점 Matching.
  >                  return 1;
  >              }
  >          }
  >          return 0;
  >      }
  >      ```

- **Time complexity.**

  > → f : 유량의 총 크기 / E : 간선의 개수 / V : 정점의 개수
  > $$
  > O(VE)
  > $$
  >

- **feature.**

  > 1. **Hopcroft Karp algorithm.**
  >
  >    > → Bipartite matching에서만 사용할 수 있는 algorithm으로 O(E*sqrt(V))라는 상대적으로 빠른 time complexity를 구할 수 있다.
  >    >
  >    > → 복잡하고 주로 사용하지 않는 algorithm.

