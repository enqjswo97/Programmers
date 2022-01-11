#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> subsets;
vector<int> subset;

//vector ũ��������
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

int makeSubset(int k, int n) { //�κ����� �����
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

        //������ key�� s�� �κ������̸� key ����
        for (vector<int> c : check) {
            int same = 0;

            for (int num : c)
                if (find(s.begin(), s.end(), num) != s.end()) same++;
            if (same == c.size()) flag = false;
        }

        if (flag) {
            set<string> column;
            for (int i = 0; i < row; i++) { //row����
                string temp = "";
                for (int a : s) temp += relation[i][a];
                column.insert(temp);
            }
            if (column.size() == row) { //�ߺ� ����
                check.push_back(s);
                answer++;
            }
        }
    }
    return answer;
}