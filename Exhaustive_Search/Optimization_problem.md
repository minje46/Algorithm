# Exhaustive Search

- **Exhaustive search is the way of checking all possibilities.**

  <br>

  (완전탐색이란, 가능한 방법을 전부 확인해보는 방식을 말한다.)

  > - Various exhaustive search
  >   1. Brute force
  >   2. Divide & conquer
  >   3. Permutation (time complexity : O(N!))
  >   4. ***Optimization Problems [TSP]***
  >   5. BFS / DFS[Backtracking]
  >   6. Bit mask

------

## 4. Optimization problems. [TSP]

- **TSP(Travelling Salesman Problem) is finding the minimum weighted path as a Hamiltonian cycle on weighted complete graph.**

  <br>

  (순회 세일즈맨 문제(TSP)는 각 변에 가중치가 주어진 완전 그래프에서 가장 작은 가중치를 가지는 해밀톤 회로를 구하는 문제이다.)

- To solve the TSP, there are diverse algorithms. 
  At first, it takes lots of time complex using brute-force.
  Second, it takes less time complex using DP compared to exhaustive search though, it should have less than 20 vertexes.

  <br>(TSP를 해결하기 위한 다양한 알고리즘이 있는데, brute-force 방식을 이용하면 시간복잡도가 너무 커진다.
  그래서 Dynamic Programming을 이용하지만, DP를 이용해도 정점이 20개가 넘을 경우, 시간 소요가 커진다.)

  ![image](https://user-images.githubusercontent.com/23169707/50631747-5c9e4580-0efa-11e9-9d4c-b050e529f1a6.png)

  > - Psuedo-code
  >
  >   ```c++
  >   int W[][] //그래프의 간선 길이 
  >   int D[][] //n, V-{v1} 
  >   
  >   tsp(n){ //n: 정점의 수
  >   	for(int i = 2; i<= n-2; i++){
  >   		D[i][0] = W[i][1] //D[vi][0]를 W[i][1]로 초기화
  >   	}
  >   	for(int k = 1; k<= n-2; k++)
  >   		for k개의 정점을 포함한 V-{v1}의 모든 subset에 대해
  >   			for A에 속하지 않고 v1이 아닌 vi에 대해
  >   				D[i][A] = min(W[i][j] + D[vj]][A-{vj}])
  >   	D[1][V-{v1}] = min(W[1][j] + D[vj][A - {v1}])
  >   	return D[1][v-{v1}]
  >   }
  >   ```

- **Time complexity.**

  > $$
  > O(N!)
  > $$
  >

- **Feature.**

  > 1. TSP는 **NP hard** 문제이다.
  >
  >    > * NP-Hard (Nondeterministic Polynomial - Hard)
  >    >
  >    >   → **다항식으로** 표현하기 힘들거나 or **표현할 수 없는** 문제를 말한다. (다항식으로 표현될 수 있는지 여부가 아직 의문.)
  >    >
  >    >   → NP-Hard 문제는, TSP와 같이 **모든 경우의 수를 일일히 확인**해보는 방법 이외에는 다항식 처럼 답을 풀이할 수 없는 문제를 말한다.
  >
  > 2. 시간 복잡도가 O(N!)으로 최악의 시간 복잡도를 가진다.
  >
  > 3. DP를 사용하더라도 빠른 탐색이 불가능 하기 때문에, 실제로는 Greedy로 "shortest path"는 구하지 못하더라도 대안이 될 수 있는 "not bad path"를 구하는 용도로 사용되기도 한다.

