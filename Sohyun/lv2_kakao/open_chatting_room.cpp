#include <string>
#include <vector>
#include <map>
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

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> db;

    for (int i = 0; i < record.size(); i++) {

        vector<string> data = split(record[i], ' ');

        if (data.front() == "Change" || data.front() == "Enter") {
            db[data[1]] = data[2];
        }
        else continue;
    }

    for (int i = 0; i < record.size(); i++) {
        vector<string> data = split(record[i], ' ');
        string msg = "";
        string nikname = "";

        if (data.front() == "Enter") msg = "님이 들어왔습니다.";
        else if (data.front() == "Leave") msg = "님이 나갔습니다.";
        else continue;

        nikname = db[data[1]];
        answer.push_back(nikname + msg);
    }
    return answer;
}