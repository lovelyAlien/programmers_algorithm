#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0;i<phone_book.size()-1; i++){
        string num = phone_book[i];
        string tmp = phone_book[i+1].substr(0,num.size());
        if(num==tmp) return false;
    }
    return answer;
}