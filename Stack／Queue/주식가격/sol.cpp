#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack <int> st;
    int c_t = 0;
    int size = prices.size();
    answer.assign(prices.size(),0);
    
    for (int i = 0; i < size; i++) {
        
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        answer[st.top()] = size - 1 - st.top();
        st.pop();
    }
    return answer;
}