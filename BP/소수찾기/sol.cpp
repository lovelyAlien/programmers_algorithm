#include <string> 
#include <vector>
using namespace std;
int answer = 0;
bool sel[10];
bool visit[10000000];

bool isPrime(int num) {
    if (num == 0 || num == 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void dfs(string s, string res) {
    
    if (res != "" && !visit[stoi(res)]) {
        int num = stoi(res);
        visit[num] = true;
        if (isPrime(num)) answer++; 
    }
    for (int i = 0; i < s.size(); i++) {
        if (sel[i]) continue;
        sel[i] = true;
        dfs(s, res + s[i]);
        sel[i] = false;
    }
}
int solution(string numbers) {

    
    dfs(numbers, "");
    return answer;
}