# Exhaustive Search

- **Exhaustive search is the way of checking all possibilities.**

  <br>

  (완전탐색이란, 가능한 방법을 전부 확인해보는 방식을 말한다.)

  > - Various exhaustive search
  >   1. Brute force
  >   2. ***Divide & conquer***
  >   3. Permutation (time complexity : O(N!))
  >   4. Optimization Problems [TSP]
  >   5. BFS / DFS[Backtracking]
  >   6. Bit mask

------

## 2. Divide & Conquer

- **Divide and conquer algorithm is that dividing each probelms in a small way and solve each problem, then get the answer with merging.**

  <br>

  (분할정복 알고리즘은 문제를 나눌 수 없을 때까지 나누어서 각각을 풀면서 다시 합병하여 문제의 답을 얻는 알고리즘이다.)

  ![image](https://user-images.githubusercontent.com/23169707/50630760-57d2a380-0f85-11e9-8390-809da17b1d59.png)

  > - Algorithm
  >
  >   1. Divide : If divide is possible, 2개 이상의 문제로 divide.
  >   2. Conquer : Divided problem이 여전히 divide is possible이라면, 1번을 재수행.
  >   3. Conquer : If divide is impossible, solve the problem.
  >   4. Merge : Conquer한 문제들을 merge하면서 original 문제의 answer를 구한다.
  >
  > - Psuedo-code
  >
  >   ```c++
  >   //Psedo Code 
  >   int x; // 찾으려는 수, search value 
  >   int[] S = new int[...]; // 찾고자 하는 수가 들어있는 배열, n size array 
  >   
  >   index location(int left, int right)
  >   { 
  >       int mid = (left+right)/2; 
  >       
  >       if(left > right) 
  >           return 0; // 못 찾은 경우 
  >       else
  >       {  
  >           if( x == S[mid] ) 
  >               return mid; 
  >           else if( x < S[mid] ) 
  >               return location(left, mid); // 위치 조정하고 다시 호출 
  >           else 
  >               return location(mid+1, right); 
  >       }
  >   }
  >   
  >   ```

- **Time complexity.**

  > $$
  > O(NlogN)
  > $$
  >

- **Feature.**

  > 1. Problem divide를 통해, 어려운 문제를 해결할 수 있다는 **biggest advantage.**
  > 2. 문제를 나누어 해결한다는 것은, **문제를 parallel solve할 수 있다는 advantage.**
  > 3. **Recursive** method를 이용하기 때문에 **overhead 발생.**
  > 4. Stack에 다양한 data를 저장하고 있어야 하기에, **stack overflow or memory overhead.** 