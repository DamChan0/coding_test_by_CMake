#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int x, int y, vector<vector<int>> &field, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < field.size() && ny >= 0 && ny < field[0].size() && field[nx][ny] && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> field(M, vector<int>(N, 0));
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        for (int i = 0; i < K; ++i)
        {
            int X, Y;
            cin >> X >> Y;
            field[X][Y] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (field[i][j] && !visited[i][j])
                {
                    bfs(i, j, field, visited);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
