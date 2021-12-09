#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector <int> basket;
    basket.push_back(0);
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] == 0)continue;
            else
            {
                basket.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;

                if (basket[basket.size() - 1] == basket[basket.size() - 2]) {
                    basket.erase(basket.begin() + basket.size() - 1);
                    basket.erase(basket.begin() + basket.size() - 1);
                    answer += 2;
                }
                break;
            }
        }
    }


    return answer;
}