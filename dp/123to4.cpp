/*정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 4가지가 있다. 합을 나타낼 때는
수를 1개 이상 사용해야 한다. 합을 이루고 있는 수의 순서만 다른 것은 같은 것으로
친다.

1+1+1+1
2+1+1 (1+1+2, 1+2+1)
2+2
1+3 (3+1)
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는
프로그램을 작성하시오.*/
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> dp(MAX_N + 1, vector<int>(4, 0));

  // 초기 조건 설정
  dp[1][1] = 1;
  dp[2][1] = 1;
  dp[2][2] = 1;
  dp[3][1] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;

  // DP 배열 채우기
  for (int i = 4; i <= MAX_N; i++) {
    dp[i][1] = dp[i - 1][1];
    dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
  }

  int T;
  cin >> T;

  std::vector<int> ans;

  while (T--) {
    int n;
    cin >> n;
    ans.push_back(dp[n][1] + dp[n][2] + dp[n][3]);
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}

/*dp[n][1] = dp[n-1][1]입니다. (dp[n-1][2] + dp[n-1][3]은 포함되지 않습니다)

이유: n-1을 만드는 방법 중 이미 1로 끝나는 경우에만 1을 더해 n을 만들 수
있습니다. 만약 n-1을 만드는 방법 중 2나 3으로 끝나는 경우에 1을 더하면, 그것은
각각 dp[n][2]와 dp[n][3]에 이미 포함되어 있습니다.


dp[n][2] = dp[n-2][1] + dp[n-2][2]입니다.

이유: n-2를 만드는 방법 중 1이나 2로 끝나는 경우에만 2를 더해 n을 만들 수
있습니다. dp[n-2][3]에 2를 더하면 새로운 경우가 되므로 포함하지 않습니다.


dp[n][3] = dp[n-3][1] + dp[n-3][2] + dp[n-3][3]입니다.

이유: n-3을 만드는 모든 방법에 3을 더해 n을 만들 수 있습니다.


dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-2][1] + dp[n-2][2] + dp[n-3][1] +
dp[n-3][2] + dp[n-3][3]
*/