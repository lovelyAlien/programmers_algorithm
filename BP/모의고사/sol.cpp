#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> a = { 1, 2, 3, 4, 5 };
    vector<int> b = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> c = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int a_cnt = 0;
    int b_cnt = 0;
    int c_cnt = 0;
    vector<int> answer;
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a[i % 5]) a_cnt++;
        if (answers[i] == b[i % 8]) b_cnt++;
        if (answers[i] == c[i % 10]) c_cnt++;
    }
    int max_cnt = max(a_cnt, max(b_cnt, c_cnt));

    if (max_cnt == a_cnt) answer.push_back(1);
    if (max_cnt == b_cnt) answer.push_back(2);
    if (max_cnt == c_cnt) answer.push_back(3);
    return answer;
}