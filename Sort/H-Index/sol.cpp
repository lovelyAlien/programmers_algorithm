#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//이진탐색
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    int l = 0; 
    int r = citations.size();
    while(l<=r){
        int mid= (l+r) /2;
        int cnt=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=mid) cnt++;
            else break;
        }
        
        if(cnt>=mid){
            answer=mid;
            l=mid+1;
        }
        else 
            r=mid-1;
    }
   
    return answer; 
}
