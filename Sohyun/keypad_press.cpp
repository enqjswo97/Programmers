#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    //keypad �ʱ�ȭ
    vector <pair<int, int> > keypad;

    keypad.push_back(make_pair(1, 3)); //0
    keypad.push_back(make_pair(0, 0)); //1
    keypad.push_back(make_pair(1, 0)); //2
    keypad.push_back(make_pair(2, 0)); //3
    keypad.push_back(make_pair(0, 1)); //4
    keypad.push_back(make_pair(1, 1)); //5
    keypad.push_back(make_pair(2, 1)); //6
    keypad.push_back(make_pair(0, 2)); //7
    keypad.push_back(make_pair(1, 2)); //8
    keypad.push_back(make_pair(2, 2)); //9

    //�޼� �������� ������ ���
    vector <pair<int, int> > left;
    vector <pair<int, int> > right;

    left.push_back(make_pair(0, 3)); //���� ��ġ *
    right.push_back(make_pair(2, 3)); //���� ��ġ #

    for (int i = 0; i < numbers.size(); i++) {
        //1,4,7 ������ �޼�
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            left.push_back(keypad[numbers[i]]);
            answer.push_back('L');
        }
        //3,6,9 ������ ������
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {

            right.push_back(keypad[numbers[i]]);
            answer.push_back('R');
        }
        //2,5,8,0 ����� ��
        else {
            int L_length = abs(keypad[numbers[i]].first - left.back().first)
                + abs(keypad[numbers[i]].second - left.back().second);
            int R_length = abs(keypad[numbers[i]].first - right.back().first)
                + abs(keypad[numbers[i]].second - right.back().second);

            if (L_length > R_length) {
                right.push_back(keypad[numbers[i]]);
                answer.push_back('R');

            }
            else if (L_length < R_length) {
                left.push_back(keypad[numbers[i]]);
                answer.push_back('L');
            }
            else { //�Ÿ��� ���� ���
                if (hand == "right") {
                    right.push_back(keypad[numbers[i]]);
                    answer.push_back('R');
                }
                else {
                    left.push_back(keypad[numbers[i]]);
                    answer.push_back('L');
                }
            }
        }
    }

    return answer;
}