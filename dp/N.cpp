#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int solution(int N, int number) {
  // 각 N의 사용 횟수에 따른 가능한 수들을 저장하는 배열
  vector<unordered_set<int>> possible_numbers(8);  // 최대 사용 횟수는 8
  int base = 0;

  // N이 한 번 사용된 경우부터 최대 8번 사용된 경우까지 탐색
  for (int i = 0; i < 8; ++i) {
    base = base * 10 + N;  // N이 i+1번 반복된 수를 만듦

    // 이번 사용 횟수에 가능한 수에 추가
    possible_numbers[i].insert(base);

    // 이전 사용 횟수들의 조합으로 새로운 수 생성
    for (int j = 0; j < i; ++j) {
      for (const int& op1 : possible_numbers[j]) {
        for (const int& op2 : possible_numbers[i - j - 1]) {
          possible_numbers[i].insert(op1 + op2);
          possible_numbers[i].insert(op1 - op2);
          possible_numbers[i].insert(op1 * op2);
          if (op2 != 0) possible_numbers[i].insert(op1 / op2);
        }
      }
    }

    // 찾고자 하는 수가 생성되었는지 확인
    if (possible_numbers[i].count(number) > 0) return i + 1;
  }

  // 8보다 큰 경우는 -1 반환
  return -1;
}

// 예시를 실행하는 메인 함수
int main() {
  int N1 = 5, number1 = 12;
  int N2 = 2, number2 = 11;

  int result1 = solution(N1, number1);
  int result2 = solution(N2, number2);

  // 결과 출력
  cout << "Result 1: " << result1 << endl;  // 예상 결과: 4
  cout << "Result 2: " << result2 << endl;  // 예상 결과: 3

  return 0;
}
