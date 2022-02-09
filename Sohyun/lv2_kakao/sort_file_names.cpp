#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<pair<string, string>, int>& a, const pair<pair<string, string>, int>& b) {
    string astr = a.first.first, bstr = b.first.first;
    transform(astr.begin(), astr.end(), astr.begin(), ::tolower);
    transform(bstr.begin(), bstr.end(), bstr.begin(), ::tolower);

    if (astr == bstr) return stoi(a.first.second) < stoi(b.first.second);
    return astr < bstr;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<pair<string, string>, int>> ret;

    for (int i = 0; i < files.size(); i++) {
        string head, num;
        int n;
        for (int j = 0; j < files[i].size(); j++) {
            if (files[i][j] >= '0' && files[i][j] <= '9') {
                n = j;
                break;
            }
            else head.push_back(files[i][j]);
        }
        for (; n < files[i].size(); n++) {
            if (files[i][n] >= '0' && files[i][n] <= '9')num.push_back(files[i][n]);
            else break;
        }

        ret.push_back(make_pair(make_pair(head, num), i));
    }

    stable_sort(ret.begin(), ret.end(), cmp);

    for (pair<pair<string, string>, int> file : ret)
        answer.push_back(files[file.second]);

    return answer;
}