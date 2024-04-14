#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 상하좌우 이동을 위한 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// BFS 함수 정의
int bfs(vector<vector<int>> &tomatoes, int M, int N, int startX, int startY)
{
    queue<pair<int, int>> q;
    int days = -1; // 시작일을 0일로 치지 않고 -1로 설정하여 계산 시작

    // 익은 토마토의 위치를 큐에 추가
    q.push(make_pair(startX, startY));

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // 상하좌우로 이동하면서 익지 않은 토마토를 익힘

            for (int j = 0; j < 4; ++j)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && tomatoes[nx][ny] == 0)
                {
                    tomatoes[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        days++; // 하루가 지남
    }

    // 모든 토마토가 익었는지 확인
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tomatoes[i][j] == 0)
            {
                // 익지 않은 토마토가 남아있으면 -1 반환
                return -1;
            }
        }
    }

    // 모든 토마토가 익었을 때의 최소 일수 반환
    return days;
}

int main()
{
    int M, N;
    cin >> M >> N;

    // 토마토 상태를 나타내는 2차원 배열
    vector<vector<int>> tomatoes(N, vector<int>(M, 0));

    // 토마토 정보 입력 받기
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> tomatoes[i][j];
        }
    }

    // 익은 토마토의 위치에서 BFS 함수 호출하여 결과 출력
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tomatoes[i][j] == 1)
            {
                cout << bfs(tomatoes, M, N, i, j) << endl;
                return 0;
            }
        }
    }

    return 0;
}