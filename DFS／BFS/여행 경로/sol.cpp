#include <string>
#include <vector>
#include <unordered_map> 
#include <algorithm> 
using namespace std;

void dfs(string start, vector<vector<string>>& tickets, unordered_map <string, vector<pair<int, string>>> &m, vector<bool> &visit, vector<string> &answer) {
    for (int i = 0; i < m[start].size(); i++) {
        pair<int, string> next = m[start][i];
        if (!visit[next.first]) {
            visit[next.first] = true;
            dfs(next.second, tickets, m, visit, answer);
        }
    }
    //끝 장소부터 경로에 추가된다.
    answer.push_back(start);
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    //key: A, value: A에 연결된 다른 공항들의 집합
    unordered_map <string, vector<pair<int, string>>> m; 
    vector<bool> visit(tickets.size(), false);
    //알파벳 순서로 정렬
    sort(tickets.begin(), tickets.end()); 

    for (int i = 0; i < tickets.size(); i++) {
        m[tickets[i][0]].push_back({ i,tickets[i][1] });
    }
    dfs("ICN", tickets, m, visit, answer);
    //처음 장소부터 경로가 시작되기 위해서 경로를 반전해준다.
    reverse(answer.begin(), answer.end()); 
    return answer;
}