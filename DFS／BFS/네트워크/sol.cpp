#include <string>
#include <vector>
#include <queue> 
using namespace std;
bool visit[200];

void bfs(int &n, vector<vector<int>> &computers, int start){
    queue <int> q;
    q.push(start);
    visit[start]=true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        

        for(int i=0;i<n;i++){
            if(computers[cur][i]==1 && !visit[i]){ 
                q.push(i);
                visit[i]=true;
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0;i<n;i++){
        if(!visit[i]){
            answer++;
            bfs(n, computers, i);
        }
            
    }
    return answer;
}