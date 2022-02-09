#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> game(int x, int n) {
    vector<char> ret;

    if (x == 0) ret.push_back(x + '0');
    while (x > 1) {
        int rest = x % n;

        if (rest >= 10) {
            switch (rest) {
            case 10: {
                ret.push_back('A');
                break;
            }
            case 11: {
                ret.push_back('B');
                break;
            }
            case 12: {
                ret.push_back('C');
                break;
            }
            case 13: {
                ret.push_back('D');
                break;
            }
            case 14: {
                ret.push_back('E');
                break;
            }
            case 15: {
                ret.push_back('F');
                break;
            }
            }
        }
        else if (rest < 10) ret.push_back(rest + '0');
        x = x / n;
    }
    if (x != 0)ret.push_back(x + '0');
    reverse(ret.begin(), ret.end());

    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector <char> temp;
    int cnt = 0;

    int i = 0;
    while (cnt <= m * t) {
        vector<char> number = game(i, n);
        for (int j : number) {
            temp.push_back(j);
            cnt++;
        }
        i++;
    }

    for (int l = 1; l <= t; l++) {
        int k = (p - 1) + (l - 1) * m;
        answer.push_back(temp[k]);
    }

    return answer;
}