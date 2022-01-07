#include <string>
#include <vector>
#include <iostream>
using namespace std;

int compressStr(string s, int len)
{
    vector<string> str;
    string ret = "";

    int i;
    for (i = 0; i <= s.size() - len; i += len)
        str.push_back(s.substr(i, len));
    if (i < s.size()) //len길이가 안되는 만큼의 문자열이 남았을 때 (ex) aab bac cc)
        str.push_back(s.substr(i, s.size()));

    int cnt = 1;
    for (int i = 0; i < str.size() - 1; i += cnt) {
        cnt = 1;
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] != str[j]) {
                if (cnt != 1) ret += to_string(cnt);
                ret += str[i];
                break;

            }
            else cnt++;
        }
    }
    if (cnt != 1) ret += to_string(cnt);

    ret += str.back();
    return ret.size();
}

int solution(string s) {
    int answer = 1000;

    for (int i = 1; i <= s.size() / 2; i++)
        answer = min(compressStr(s, i), answer);

    return answer;
}