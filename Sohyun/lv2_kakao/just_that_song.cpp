#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> ret;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == delimiter) {
            ret.push_back(temp);
            temp.clear();
            continue;
        }
        temp.push_back(str[i]);
    }
    ret.push_back(temp);

    return ret;
}

int findMinute(string start, string end) {
    int sMin = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
    int eMin = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));
    return (eMin - sMin);
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector <pair<string, string> > plays; //song name , played code

    for (string& musicinfo : musicinfos) {
        vector<string> music;
        music = split(musicinfo, ',');
        int time = findMinute(music[0], music[1]);
        string code = "";

        int cnt = 0;
        while (cnt < time) {
            for (int i = 0; i < music[3].size(); i++) {
                code.push_back(music[3][i]);
                ++cnt;
                if ((i != music[3].size() - 1) && music[3][i + 1] == '#') --cnt;
                if (cnt == time) break;
            }
        }
        plays.push_back(make_pair(music[2], code));
    }

    int lm = 0; // the longest music
    for (pair<string, string> p : plays) {
        string str = p.second;

        while (str.size() >= m.size()) {
            int idx = str.find(m);
            if (idx != -1 && str[idx + m.size()] != '#' && p.second.size() > lm) {
                answer = p.first;
                lm = p.second.size();
                break;

            }
            else if (idx != -1 && str[idx + m.size()] == '#') {
                int rest = idx + m.size() + 1;
                str = str.substr(rest, p.second.size() - rest);
            }
            else break;
        }
    }

    return answer;
}


