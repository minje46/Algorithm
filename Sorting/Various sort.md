### Various Sort

------

## 1. Insertion & Selection sort

- The **main point** of insertion sort is **search and insert.**

  > Search : search the list for a correct position.
  >
  > Insert : Insert new value in correct position directly.

  <img width="293" alt="insertion" src="https://user-images.githubusercontent.com/23169707/46024607-247caf00-c122-11e8-9984-d1aa7588d86e.png">

- Performace 
  $$
  O(n^2)
  $$

- Simple and good for a short list



* The **main point** of selection sort is **search the largest value and swap.**

  <img width="300" alt="selection" src="https://user-images.githubusercontent.com/23169707/46024956-bf758900-c122-11e8-839e-80601f1b2a7a.png">

* Performance
  $$
  O(n^2)
  $$

* Useful for a small list stored in EEPROM or Flash memroy.





------

## 2. Bubble Sort 

- The **main point** of bubble sort is **compare two values  and swap.**

  <img width="300" alt="bubble" src="https://user-images.githubusercontent.com/23169707/46025260-82f65d00-c123-11e8-8be9-a3b5e11f2bfb.png">

- Performance
  $$
  O(n^2)
  $$

- Similar to selection sort though, it is the slowest sort. 





------

## 3. Merge Sort 

- The **main point** of merge sort is **split and merge.**

  > Split : Divide a list successively into two unsorted sub lists.
  >
  > Merge : Merge the two sub lists successively into a single sorted list.

  <img width="581" alt="merge" src="https://user-images.githubusercontent.com/23169707/46024302-73761480-c121-11e8-9080-31fb23308847.png">

- Performace 
  $$
  O(n log2 n)
  $$

- Stable sort

- O(n) storage space





------

## 4. Heap Sort 

- The **main point** of heap sort is **build heap and swap and build heap again.**

  > Build max heap : First, **build a max heap** with original input array.
  >
  > Swap and delete : After built max heap, the **root node is the largest value** so it will **swap with the last leaf node.** Then **delete the last leaf node.**
  >
  > Build max heap again : Last, build a max heap **with reduced array which is deleted the largest value before.**

  <img width="149" alt="heap" src="https://user-images.githubusercontent.com/23169707/46025774-a40b7d80-c124-11e8-8735-7d21f0fbaca9.png">

- Performance
  $$
  O(n log2 n)
  $$

- Small need for storage space.