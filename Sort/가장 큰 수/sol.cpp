#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//합친 문자를 비교해서 큰 순으로 정렬하기, ex) "10", "6" 있다면 "106"과 "610" 비교 후 큰 순으로 정렬
//"610"이 더 크므로 "6", "10" 순서로 정렬하게 된다.
bool cmp(const string& a, const string& b){
    if(a+b > b+a) return true; 
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for(int i=0;i<numbers.size();i++){
        tmp.push_back(to_string(numbers[i]));
    }
    sort(tmp.begin(), tmp.end(), cmp);
    
    //가장 큰 수의 맨 앞 숫자가 0이면 0을 반환.
    if(tmp[0]=="0") answer = "0";
    else{
        for(int i=0;i<tmp.size();i++){
        answer+=tmp[i];
        }
        
    }
    return answer;
}