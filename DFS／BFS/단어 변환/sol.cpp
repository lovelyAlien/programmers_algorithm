#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visit[50];

bool check(string &cur, string &next){
    int cnt=0;
    for(int i=0;i<cur.length();i++){
        if(cur[i]!=next[i]) 
            cnt++;
       
    }

    if(cnt==1) return true;
    else return false;
}
int bfs(string &begin, string &target, vector<string> &words){
    
    queue <pair<string,int>> q;

    q.push({begin,0});
   

    while(!q.empty()){
        pair<string,int> cur= q.front();
        q.pop();
        if(cur.first==target) return cur.second;

        for(int i=0;i<words.size();i++){
            if(check(cur.first, words[i]) && !visit[i]){
                q.push({words[i], cur.second+1});
                visit[i]=true;
            }
        }
    }



    return 0;
    
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    answer= bfs(begin, target, words);
    return answer;
}