#include <iostream>
#include <vector>

using namespace std;

// 벌집의 숫자를 시계 방향으로 채우는 함수
void fillHexagon(int n, vector<int> &result)
{
  int num = 1;
  result.push_back(num); // 첫 번째 숫자 1 추가

  // n층의 벌집을 채우기 위한 루프
  for (int i = 0; i < n; ++i)
  {
    // n층의 시작 숫자와 종료 숫자 계산
    int start = num + 1;
    int end = num + (6 * (i + 1));

    // 짝수층일 때는 오른쪽 방향으로 숫자를 추가
    if (i % 2 == 0)
    {
      for (int j = start; j <= end; ++j)
      {
        result.push_back(j);
      }
    }
    // 홀수층일 때는 왼쪽 방향으로 숫자를 추가
    else
    {
      for (int j = end; j >= start; --j)
      {
        result.push_back(j);
      }
    }

    num = end; // 다음 층의 시작 숫자 갱신
  }
}

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  vector<int> result;
  fillHexagon(n, result);

  // 결과 출력
  cout << "Result: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
