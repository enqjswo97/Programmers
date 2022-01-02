#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    float similarity = 0;
    vector <string> A, B;

    for (int i = 0; i < str1.length() - 1; i++) {
        string temp = "";

        if (str1[i] >= 'a' && str1[i] <= 'z') str1[i] -= 32;
        if (str1[i + 1] >= 'a' && str1[i + 1] <= 'z') str1[i + 1] -= 32;

        if ((str1[i] >= 'A' && str1[i] <= 'Z') && (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')) {
            temp += str1[i], temp += str1[i + 1];
            A.push_back(temp);
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        string temp = "";

        if (str2[i] >= 'a' && str2[i] <= 'z') str2[i] -= 32;
        if (str2[i + 1] >= 'a' && str2[i + 1] <= 'z') str2[i + 1] -= 32;

        if ((str2[i] >= 'A' && str2[i] <= 'Z') && (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')) {
            temp += str2[i], temp += str2[i + 1];
            B.push_back(temp);
        }
    }

    if (A.size() == 0) {
        if (B.size() == 0) return 65536;
        else return 0;
    }

    vector <string> inter, uni;

    for (int i = 0; i < A.size(); i++) {
        bool same = false;
        for (int j = 0; j < B.size(); j++) {
            if (A[i] == B[j]) {
                inter.push_back(A[i]);
                B.erase(B.begin() + j);
                same = true;
                break;
            }
        }
        if (!same) uni.push_back(A[i]);
    }

    for (int i = 0; i < B.size(); i++) uni.push_back(B[i]);
    for (int i = 0; i < inter.size(); i++) uni.push_back(inter[i]);

    similarity = (float)inter.size() / (float)uni.size();
    answer = int(similarity * 65536);

    return answer;
}