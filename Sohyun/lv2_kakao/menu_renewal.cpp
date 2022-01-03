#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> set;

void makeSubset(string str, int idx, string subset) {

    if (subset.size() >= 2) set[subset]++;

    for (int i = idx + 1; i < str.size(); i++) { //subset without empty set
        subset.push_back(str[i]);
        makeSubset(str, i, subset);
        subset.pop_back(); //why?
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string& order : orders) {
        sort(order.begin(), order.end());
        makeSubset(order, -1, "");
    }

    for (int crs : course) {
        vector<string> ret;
        int max_value = 0;
        for (auto iter : set) {
            if (iter.first.size() == crs)
                max_value = max(iter.second, max_value);
        }

        for (auto iter : set) {
            if (iter.first.size() == crs && iter.second == max_value && max_value >= 2)
                answer.push_back(iter.first);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}
