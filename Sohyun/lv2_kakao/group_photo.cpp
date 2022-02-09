#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = { 'A','C','F','J','M','N','R', 'T' };
    sort(friends.begin(), friends.end());

    do {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int interval = abs(find(friends.begin(), friends.end(), data[i][0])
                - find(friends.begin(), friends.end(), data[i][2])) - 1;
            int cond = data[i][4] - '0';

            if (data[i][3] == '=') {
                if (interval != cond) flag = false;

            }
            else if (data[i][3] == '>') {
                if (interval <= cond) flag = false;

            }
            else if (data[i][3] == '<') {
                if (interval >= cond) flag = false;
            }
            if (!flag) break;
        }
        if (flag)answer++;
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}