#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    vector<int> ret;

    int dy[4] = { 0,0,-1,1 };
    int dx[4] = { 1,-1,0,0 };

    int arr[100][101] = { 0, };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (picture[i][j] == 0) continue; //색칠 안한 영역

            if (arr[i][j] == 0) {
                int area_size = 1;
                queue<pair<int, int> > q;

                q.push(pair(i, j));
                arr[i][j] = 1;

                while (!q.empty()) {
                    for (int dir = 0; dir < 4; dir++) {
                        int sx = q.front().first + dx[dir];
                        int sy = q.front().second + dy[dir];

                        if (sx >= 0 && sx < m && sy >= 0 && sy < n) {
                            if (arr[sx][sy] == 0 && picture[i][j] == picture[sx][sy]) {
                                arr[sx][sy] = 1;
                                area_size++;
                                q.push(pair(sx, sy));
                            }
                        }
                    }
                    q.pop();
                }
                ret.push_back(area_size);

            }
            else continue;
        }
    }

    int Max = 0;
    for (int a : ret) Max = max(a, Max);

    answer[0] = ret.size();
    answer[1] = Max;

    return answer;
}