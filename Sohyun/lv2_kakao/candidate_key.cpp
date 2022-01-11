#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> subsets;
vector<int> subset;

//vector 크기작은순
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

int makeSubset(int k, int n) { //부분집합 만들기
    if (k == n + 1) subsets.push_back(subset);
    else {
        subset.push_back(k);
        makeSubset(k + 1, n);
        subset.pop_back();
        makeSubset(k + 1, n);
    }
    return 0;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<vector<int>>check;

    int row = relation.size();
    int col = relation.front().size();

    makeSubset(0, col - 1);
    sort(subsets.begin(), subsets.end(), cmp);

    for (vector<int> s : subsets) {
        bool flag = true;

        //기존에 key가 s의 부분집합이면 key 제외
        for (vector<int> c : check) {
            int same = 0;

            for (int num : c)
                if (find(s.begin(), s.end(), num) != s.end()) same++;
            if (same == c.size()) flag = false;
        }

        if (flag) {
            set<string> column;
            for (int i = 0; i < row; i++) { //row개수
                string temp = "";
                for (int a : s) temp += relation[i][a];
                column.insert(temp);
            }
            if (column.size() == row) { //중복 없음
                check.push_back(s);
                answer++;
            }
        }
    }
    return answer;
}