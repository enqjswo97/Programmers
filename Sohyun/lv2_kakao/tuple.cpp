#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) { //내림차순
    // if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string num = "";
    map <int, int> m;

    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num.push_back(s[i]);
        }
        else if (s[i] == ',') {
            if (num.size() != 0) {
                m[stoi(num)]++;
                num = "";
            }
        }
        else if (s[i] == '}') {
            m[stoi(num)]++;
            num = "";
        }
        else continue;
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) answer.push_back(v[i].first);

    return answer;
}