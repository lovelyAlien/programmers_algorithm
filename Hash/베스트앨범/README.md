## 문제

### ⚡[문제 링크 : 프로그래머스](https://programmers.co.kr/learn/courses/30/lessons/42579)



## 문제 풀이

### 📚 알고리즘

> - **hash를 이용하여 plays의 노래의 정보를 입력 한다. (장르, 재생 횟수, 고유 번호)**
> - **장르 별 총 재생 횟수도 hash를 이용하여 저장한다.**
> - **장르 별로 저장한 노래들을 재생 횟수를 이용하여 큰 순서대로(내림차순으로) 정렬한다.**
> - **장르 별 총 재생 횟수를 저장한 hash도 재생 횟수가 많은 순서대로(내림차순으로) 정렬한다.**
> - **반복문을 이용하여 저장된 hash에서 장르 별 최대 2개의 노래를 answer에 저장한다.**



## 복습

 ### map

> **반복문 데이터 접근 (first, second)**
> 
>  - 인덱스 기반 반복문 활욘한 예제
> 
>   :인덱스 기반은 iterator을 활용하여 begin()부터 end()까지 찾습니다. 
> 
>  ```cpp
>  for(auto iter=m.begin() ; iter!= m.end() ; iter++){
>  	cout<<iter->first<<" "<<iter->second<<endl;
>  }
>  ```
> 
> 
>
>  - 범위 기반 반복문 활용한 예제
> 
>  ```cpp
>  for(auto iter : m){
>  	cout<<iter.first<<" "<<iter.second<<endl;
>  }
>  ```



### vector::assign  

> C/C++ 확대 축소
> 
>```cpp
> template <class InputIterator>
> void assign(InputIterator first, InputIterator last);
> void assign(size_type n, const T& u);
> ```
> 
>벡터에 새로운 내용을 집어 넣는다. 벡터 객체에 **이전에 있었던 원소들은 모두 삭제**하고, 인자로 받은 새로운 내용을 집어 넣는다.
> 
>첫번째 형태의 함수의 경우 `first` 부터 `last` 까지에 있는 원소들의 내용이 벡터에 들어가게 된다. (first 부터 last 바로 직전 원소 까지) 물론, 원래 벡터에 있었던 원소들은 삭제된다.
> 
>두번째 형태는 원래 내용을 다 지우고 원소 `u` 를 `n` 개 가지는 벡터로 만든다.
>
>
>
>```cpp
>  /*
>
> 이 예제는
>http://www.cplusplus.com/reference/stl/vector/assign/
> 에서 가져왔습니다
> 
> */
> #include <iostream>
> #include <vector>
>using namespace std;
> 
>
> int main() {
>vector<int> first;
> vector<int> second;
> vector<int> third;
> 
> first.assign(7, 100);  // 100 을 7 번 반복해서 집어 넣는다.
> 
>vector<int>::iterator it;
> it = first.begin() + 1;
>
> second.assign(it, first.end() - 1);  // first 의 처음과 끝을 제외한 원소들
>
> int myints[] = {1776, 7, 4};
>third.assign(myints, myints + 3);  // 배열로 부터 받는다.
> 
> cout << "Size of first: " << int(first.size()) << endl;
> cout << "Size of second: " << int(second.size()) << endl;
> cout << "Size of third: " << int(third.size()) << endl;
> return 0;
>}
> ```
>
> 
>![img](https://modoocode.com/img/19102C4E4F6E967A10EEAF.webp "실행결과")