#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    for(auto name : completion){
        m[name]+=1;
    }
    for(auto name : participant){
        m[name]-=1;
        if(m[name]<0){
            answer=name;
            break;
        }
    }
    return answer;
    
}