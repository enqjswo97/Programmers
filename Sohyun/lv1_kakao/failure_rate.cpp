#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<float, int>& a, const pair<float, int>& b) {
    if (a.first == b.first)
        return a.second < b.second; //오름차순
    return a.first > b.first;	//내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector <int> answer;
    vector <pair<float, int> > rate;

    float deno = stages.size();

    for (int i = 1; i < N + 1; i++) { //stage
        float mol = 0;

        if (deno != 0) {
            for (int j = 0; j < stages.size(); j++) {
                if (stages[j] == i) mol++;
            }
            rate.push_back(make_pair(mol / deno, i));
            deno -= mol;
        }
        else rate.push_back(make_pair(0, i));

    }
    sort(rate.begin(), rate.end(), cmp);

    for (int i = 0; i < rate.size(); i++) answer.push_back(rate[i].second);

    return answer;
}