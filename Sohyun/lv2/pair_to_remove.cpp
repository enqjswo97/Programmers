#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack <char> st;

    for (char c : s) {
        if (st.empty() || c != st.top()) st.push(c);
        else if (c == st.top()) st.pop();
    }
    return (st.size() == 0 ? 1 : 0);
}