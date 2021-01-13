## Problem : [단어 변환](https://programmers.co.kr/learn/courses/30/lessons/43164)

> 유형 : DFS, 해시



------



## 문제 해석

- 주어진 항공권을 전부 사용하여, ICN을 시작으로 하여 공항을 전부 순회하는 경로를 구하라.
  - 이때 알파벳 순서가 앞서는 경로를 우선으로 한다.



## 해결 전략

- 그래프로 생각하고 해결하였다.
- 오일러 트레일(한붓그리기) 구현 알고리즘을 활용하여 해결하였다.
- [참고](https://sonsh0824.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B3%B5%EB%B6%804-%ED%95%9C%EB%B6%93%EA%B7%B8%EB%A6%AC%EA%B8%B0Eulerian-circuit)



## 구현

- A에 연결된 다른 공항들의 집합이 필요했다.

  - Map과 Vector를 이용하였다.
  - `unordered_map<string, vector<pair<int,string>>> m;`

- A에서 B로 가는 티켓을 사용했는지 확인을 할 필요가 있었다.

  - ```cpp
      vector<bool> visit(tickets.size(), false);
    ```
