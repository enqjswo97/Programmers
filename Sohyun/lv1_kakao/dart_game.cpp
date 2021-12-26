#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string dartResult) {

    vector<int> temp;
    int answer = 0;
    int num = 0;

    for (int i = 0; i < dartResult.size(); ++i) {

        if (dartResult[i] >= '0' && dartResult[i] <= '9') num = num * 10 + dartResult[i] - '0';

        else if (dartResult[i] == 'S') temp.push_back(num), num = 0;
        else if (dartResult[i] == 'D') temp.push_back(pow(num, 2)), num = 0;
        else if (dartResult[i] == 'T') temp.push_back(pow(num, 3)), num = 0;

        else if (dartResult[i] == '*') {
            if (temp.size() > 1) {
                temp.back() *= 2;
                temp[temp.size() - 2] *= 2;
            }
            else temp.back() *= 2;
        }
        else temp.back() = (-1) * temp.back();
    }

    for (int i = 0; i < temp.size(); ++i) answer += temp[i];

    return answer;
}

