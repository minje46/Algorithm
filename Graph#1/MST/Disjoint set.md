# Disjoint set

- **Disjoint set is a data structure that stores each element which is separated.** 

  <br>(서로소 집합은 서로 중복되지 않는 부분 집합들로 나뉘어진 원소들에 대한 정보를 저장하는 자료구조.)




# Union - Find algorithm

- **Union-Find algorithm is used to express disjoint set.** 

  <br>(Union-Find는 서로소 집합을 표현할 때 사용하는 알고리즘이다.)

- **Union-Find algorithm은 Tree strucutre를 사용한다.**

  > * Algorithm [Tree]
  >
  >   1. Initialize : `make-set(x)`
  >
  >      > → 각 Node는 모두 자신의 root node 이므로 N개의 root node를 생성하고 Initialize한다.
  >
  >   2. Uion : `union(x,y)`
  >
  >      >  → x,y의 root node를 find하고 서로 root node가 다를 경우, y를 x의 child node로 union한다.
  >      >
  >      > > **Time complexity.**
  >      > >
  >      > > → O(N)보다 작기때문에 find 가 중점.
  >
  >   3. Find : `find(x)`
  >
  >      > → Node의 root node를 find하여 same set인지 판단한다.
  >      >
  >      > > **Time complexity.**
  >      > > $$
  >      > > O(N-1)
  >      > > $$
  >      > >
  >
  > * Algorithm [Array]
  >
  >   1. Initialize : `make-set(x)`
  >
  >      > → `Array[i]=i`와 같이 각자 다른 set 번호로 initialize.
  >
  >   2. Uion : `union(x,y)`
  >
  >      >  → Array의 모든 원소를 순회하면서, y의 set 번호를 x의 set 번호로 변경한다.
  >      >
  >      >  > * **Time complexity.**
  >      >  >   $$
  >      >  >   O(N)
  >      >  >   $$
  >      >  >
  >      >  >
  >
  >   3. Find : `find(x)`
  >
  >      > → X가 속한 set 번호를 find한다.
  >      >
  >      > > **Time complexity.**
  >      > > $$
  >      > > O(1)
  >      > > $$
  >      > >
  >
  > ![union-find](https://user-images.githubusercontent.com/23169707/52753674-76788100-2fac-11e9-9756-224c99b7908a.png)
  >
  >
  >
  > * Pseudo-code
  >
  >   ```c++
  >   // Initialize
  >   int root[MAX_SIZE];
  >   for (int i = 0; i < MAX_SIZE; i++)
  >       parent[i] = i;
  >   
  >   // Find : Recursive
  >   int find(int x) 
  >   {	// Root node는 parent node번호로 자기 자신을 가진다.
  >       if (root[x] == x) 
  >           return x;
  >       else // 각 Node의 parent node를 find.
  >         return find(root[x]);
  >   }
  >   
  >   // Union
  >   void union(int x, int y)
  >   { 	// 각 원소가 속한 Tree의 Root node를 find.
  >       x = find(x);
  >       y = find(y);
  >   
  >       root[y] = x;
  >   }
  >   ```

