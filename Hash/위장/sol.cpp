#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> hash;

    for(int i=0;i<clothes.size();i++){  
        hash[clothes[i][1]]++;
        
    }
    
    unordered_map<string,int>::iterator iter;
    for(iter=hash.begin();iter!=hash.end();iter++){
        answer*=iter->second+1; //+1은 각 종류의 의상에서 선택안하는 경우를 세어준 것이다.
    }
    return answer-1; //최소 한 개의 의상은 필요하므로, 아무것도 선택하지 않는 경우 하나를 빼고 리턴한다. 
}