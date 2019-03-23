# Network Flow

- **Network flow computes the flow on the graph which has edge of "capacity".** 

  <br>

  (네트워크 프로우는 "용량"을 갖는 간선의 그래프에서 유량을 계산하는 것. )

  > ![image](https://user-images.githubusercontent.com/23169707/54863395-7af23f80-4d8b-11e9-92ad-246787a419d0.png)
  >
  > * **Terminology.**
  >   * Source : Departure of network. [네트워크의 시작]
  >   * Sink : Destination of network. [네트워크의 도착지]
  >   * Capacity : The capacity between A and B. [A에서 B로 갈 수 있는 용량]
  >   * Flow : The flow between A and B. [A에서 B로 흐르는 유량]
  >   * Residual : The residue between A and B. [A에서 B로 보낼 수 있는 잔여 용량]

- **Conditions.**

  > 1. Capacity constraint[용량의 제한] : f(a,b) <= c(a,b)
  > 2. Skew symmetry[유량의 대칭] : f(a,b) = -f(b,a)
  > 3. Flow conservation[유량의 보존] :  각 vertex에 들어오는 flow와 나가는 flow는 정확히 same.
  >
  > <img width="569" alt="Network_Flow_Conditions" src="https://user-images.githubusercontent.com/23169707/54863685-09b48b80-4d8f-11e9-9826-9aa06bf22c53.png">





