# MCMF (Minimum Cost Maximum Flow) 

- **MCMF algorithm figures out the maximum flow with minimum cost when the graph has cost and capacity value altogether.** 

  > → Basic concept : Shortest path * flow 를 반복해서 Maximum flow를 찾는다.

  <br>

  (최소 비용 최대 유량 알고리즘은 그래프 간선에 유량과 비용이 함께 존재할 때, 최소의 비용으로 흘릴 수 있는 최대의 유량을 구하는 것이다.)

- > - Algorithm
  >
  >   1. SPFA algorithm을 위한 초기 작업.
  >
  >      > → dist[] 와 in_que[], queue<> memory를 allocation.
  >
  >   2. Check the Shortest path & Possible flow.
  >
  >      > → 흘릴 수 있는 유량의 간선을 확인 : `capacity[cur][next] - flow[cur][next] > 0`
  >      >
  >      > → 최단 거리를 체크 : ` d[next] > d[cur] + dist[cur][next]`
  >
  >   3. Find the path until get sink.
  >
  >      > → Sink(도착지)에 도착할 때까지 2번을 반복해서 path를 찾는다.
  >
  >   4. Compute cost and flow.
  >
  >      > → `S→T`의 경로를 flow 와 cost를 multiply한다.
  >      >
  >      > → `tot_flow += f * dist[prev[i]][i]`
  >
  >   5. S에서 T로 도착하는 경로가 없을 때 까지 1~4번 반복.
  >
  >      ```c++
  >      void MCMF()
  >      {
  >          	while (true) // Until there is no more augmenting path.
  >      	{
  >      		int prev[MAX], d[MAX];	bool in_que[MAX] = { false };			
  >      		
  >              queue<int>que;	d[S] = 0;	in_que[S] = true;	que.push(S);
  >      		while (!que.empty())
  >      		{
  >      			int cur = que.front();	que.pop();	in_que[cur] = false;	
  >              	for (auto next : graph[cur])
  >                  {									
  >      				if (capacity[cur][next] - flow[cur][next] > 0 && d[next] > d[cur] + dist[cur][next])
  >      				{									
  >      					d[next] = d[cur] + dist[cur][next];
  >      					prev[next] = cur;		
  >      					if (!in_que[next])								
  >      						que.push(next);	in_que[next] = true;
  >      				}
  >      			}
  >      		}
  >      			
  >      		if (prev[T] == -1)
  >      			break;
  >                  
  >      		for (int i = T; i != S; i = prev[i]) // 최소 유량 f 찾기.
  >      			f = min(f, capacity[prev[i]][i] - flow[prev[i]][i]);	
  >      
  >      		for (int i = T; i != S; i = prev[i]) // MCMF 구하기.	
  >      		{											
  >      			tot_flow += f * dist[prev[i]][i]; // cost*flow.
  >      			flow[prev[i]][i] += f;	// update flow graph.	
  >      			flow[i][prev[i]] -= f;	// backward graph.
  >      		}
  >      	}
  >      }
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

