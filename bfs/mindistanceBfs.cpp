#include <queue>
#include <vector>
#include <utility>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<int>> maps, vector<vector<bool>> visited, int startX, int startY, int cnt)
{
    queue<pair<int, int>> way;
    way.push(make_pair(startX, startY));
    visited[startX][startY] = true;

    cnt = 1;

    while (!way.empty())
    {
        /* code */
        for (int j = 0; j < way.size(); j++)
        {

            int curx = way.front().first;
            int cury = way.front().second;
            way.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx == maps.size() - 1 && ny == maps[0].size() - 1)
                {
                    return cnt + 1;
                }

                if (nx >= 0 && ny >= 0 && nx < maps.size() && ny < maps[0].size() && !visited[nx][ny] && maps[nx][ny] == 1)
                {
                    way.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                }
            }
        }
        cnt++;
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    vector<vector<bool>> visited;
    int N = maps.size();
    int M = maps[0].size();

    visited.resize(N, vector<bool>(M, 0));

    answer = bfs(maps, visited, 0, 0, answer);
    return answer;
}
#include <iostream>
int main()
{
    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    int result = solution(maps);
    cout << result << endl;
    return 0;
}