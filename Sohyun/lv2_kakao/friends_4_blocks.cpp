#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1) {
        vector<pair<int, int> > erase_block;
«¡∑ª¡Ó 4∫Ì∑œ
        //find 
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char block = board[i][j];
                if (block != 'e' && block == board[i][j + 1] && block == board[i + 1][j] && block == board[i + 1][j + 1])
                    erase_block.push_back(make_pair(i, j));
            }
        }

        if (erase_block.size() == 0) break;

        //erase 
        for (int i = 0; i < erase_block.size(); i++) {
            int y = erase_block[i].first, x = erase_block[i].second;
            board[y][x] = 'e', board[y + 1][x] = 'e', board[y][x + 1] = 'e', board[y + 1][x + 1] = 'e';
        }

        //fill
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                vector<pair<int, int> > empty;
                //check down
                for (int k = i + 1; k < m; k++) {
                    if (board[k][j] == 'e') empty.push_back(make_pair(k, j));
                    else break;
                }
                if (empty.size() != 0) {
                    board[empty.back().first][empty.back().second] = board[i][j];
                    board[i][j] = 'e';
                }
            }
        }
    }

    for (string& s : board) {
        for (char c : s) if (c == 'e') answer++;
    }
    return answer;
}