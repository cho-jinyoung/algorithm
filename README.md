# algorithm
## 보안알고리즘(3학년1학기)
- A5-1
- DES
- AES
- RSA
- - - - - - - - - -
## CodingTest_Algorithm
- ①DP(Dynamic Programming) 큰 문제를 작은 문제로 나눠서 푸는 알고리즘  
  - overlapping subproblem ex)피보나치 수열 Fn=Fn-1+Fn-2에서 Fn을 큰 문제로 Fn-1, Fn-2를 작은문제로 나눈다고 생각
  - optimal substructure: 작은 문제의 정답을 합하는것으로 문제의 정답을 구함 ex)Fn-1+Fn-2=Fn
  - 접근 방식 1. Top-Down: 큰문제를 작은문제로 나눠 작은문제를 풀고 이를 이용하여 재귀호출방식으로 품 
             2. Bottom-Up: 작은문제부터 문제를 점점 크게 만들면서 문제를 품 
  - ex)BOJ_1463(1로만들기), 11726(2xn타일링), 9095(123더하기), 11052(카드구매하기), 10844(쉬운계단수), 2293(동전)
- ②BFS(Breath-First Search) 탐색시 너비를 우선으로 하는 알고리즘으로 루트노드에서 시작해 인접한 노드 먼저 탐색
  - 두 노드 사이에 최단경로 or 임의의 경로를 찾고 싶을 때 주로 사용
  - 재귀적으로 동작하지 않으며 어떤 노드를 방문했었는지를 반드시 검사해야 함
  - 방문한 노드를 차례로 저장,꺼낼 수 있는 자료구조 큐 필요(FIFO)  
  ![image](https://user-images.githubusercontent.com/54131109/76165026-f0227480-6196-11ea-9c73-4e0cd7f56ce7.png)

