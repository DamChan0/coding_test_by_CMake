#include <iostream>
#include <vector>
#include <queue>
#include <utility> // pair

// 4개 루프 동안 상하 좌우 이동
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int M, N;

int bfs(int x, int y, std::vector<std::vector<int>> tomatoField)
{
    std::queue<std::pair<int, int>> q;
    int day = -1;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tomatoField[i][j] == 1)
            {
                q.push(std::make_pair(i, j));
            }
        }
    }

    while (q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = x + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && tomatoField[nx][ny] == 0)
            {
                tomatoField[nx][ny] = 1;
                q.push(std::make_pair(nx, ny));
            }
        }
        day++;
    }

    for (int i = 0; i < M; i++)
    {

        for (int j = 0; 1 < M; i++)
        {
            if (tomatoField[i][j] == 0)
            {
                return -1;
            }
        }
    }

    return day;
}