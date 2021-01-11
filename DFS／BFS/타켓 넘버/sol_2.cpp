#include <string>
#include <vector>

using namespace std;

//비트연산 풀이
int solution(vector<int> numbers, int target) {

    int answer = 0;
    int size= numbers.size();
    for(int i=0;i<(1<<size);i++){ //계산 결과는 i의 j번째 비트가 1인지 아닌지를 의미한다.
        int sum=0;
        for(int j=0;j<size;j++){
            if(i & (1<<j)) 
                sum+=numbers[j];
            else
                sum-=numbers[j];
        }

        if(sum==target) answer++;
    }
    return answer;
}