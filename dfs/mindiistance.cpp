#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int min_length = 987654321; // 초기 최솟값 설정

vector<vector<bool>> visited;

void dfs(vector<vector<int>> &maps, int startx, int starty, int length) // length 추가
{
    if (startx == maps.size() - 1 && starty == maps[0].size() - 1)
    {                                         // 상대 팀 진영에 도달한 경우
        min_length = min(min_length, length); // 최솟값 갱신
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = startx + dx[i];
        int ny = starty + dy[i];

        if (nx >= 0 && nx < maps.size() && ny >= 0 && ny < maps[0].size() && maps[nx][ny] == 1 && !visited[nx][ny]) // 조건 수정
        {
            visited[nx][ny] = true;        // 방문 표시
            dfs(maps, nx, ny, length + 1); // 경로 길이 추가
            visited[nx][ny] = false;       // 백트래킹
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    visited.resize(maps.size(), vector<bool>(maps[0].size(), false)); // visited 배열 초기화
    dfs(maps, 0, 0, 1);                                               // 초기 위치부터 탐색 시작 (길이는 1부터 시작)
    answer = (min_length == 987654321) ? -1 : min_length;             // 도달할 수 없는 경우 -1 반환
    return answer;
}

int main()
{
    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    int result = solution(maps);
    cout << "Result: " << result << endl;
    return 0;
}
