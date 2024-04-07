#include <iostream>
#include <vector>

using namespace std;
// 유기농 배추
//  상하좌우 이동을 위한 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &field, int x, int y)
{
    // 현재 위치를 방문했음을 표시
    field[x][y] = 0;

    // 상하좌우로 이동하면서 배추가 심어져 있는지 확인
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 배추가 심어져 있는 위치라면 재귀적으로 탐색
        if (nx >= 0 && nx < field.size() && ny >= 0 && ny < field[0].size() && field[nx][ny] == 1)
        {
            dfs(field, nx, ny);
        }
    }
}

int main()
{
    int M = 0;
    int N = 0;
    int K = 0;
    int T = 0;
    int cnt = 0;

    cin >> T;
    while (T != 0)
    {
        cin >> M >> N >> K;
        vector<vector<int>> field(M, vector<int>(N, 0));

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] == 1)
                {
                    dfs(field, i, j);
                    cnt++;
                }
            }
        }

        T--;
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}