#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        int v = arr1[i] | arr2[i];
        string s;
        for (int j = 0; j < n; j++) {
            s.push_back(v % 2 ? '#' : ' ');
            v /= 2;
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
    return answer;

}

vector<string> solution2(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> binarys1, binarys2;

    for (int i = 0; i < n; i++) {

        int temp1 = arr1[i];
        int temp2 = arr2[i];

        string binary1, binary2;

        for (int k = 0; k < n; k++) {
            binary1.push_back('0');
            binary2.push_back('0');
        }

        int number1 = n - 1;
        int number2 = n - 1;

        while (number1 > -1) {

            if (temp1 == 1) {
                binary1[number1] = '1';
                break;
            }

            binary1[number1] = ((temp1 % 2) + '0');
            temp1 = temp1 / 2;

            number1 -= 1;
        }
        binarys1.push_back(binary1);

        while (number2 > -1) {
            if (temp2 == 1) {
                binary2[number2] = '1';
                break;
            }
            binary2[number2] = ((temp2 % 2) + '0');
            temp2 = temp2 / 2;

            number2 -= 1;
        }
        binarys2.push_back(binary2);
    };

    for (int i = 0; i < n; i++) {
        string ret;
        for (int j = 0; j < n; j++) {
            if (binarys1[i][j] == '1' || binarys2[i][j] == '1') {
                ret.push_back('#');
            }
            else {
                ret.push_back(' ');
            }
        }
        answer.push_back(ret);
    }

    return answer;
}
