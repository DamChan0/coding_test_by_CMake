// 체육복 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = n - lost.size();
  sort(lost.begin(), lost.end());
  sort(reserve.begin(), reserve.end());

  for (int i = 0; i < reserve.size(); ++i) {
    auto it = find(lost.begin(), lost.end(), reserve[i]);
    int index = distance(lost.begin(), it);
    if (it != lost.end()) {  // 만약 있다면
      lost[index] = 0;
      reserve[i] = 0;
      ++answer;  // answer를 1 증가시킴
    }
  }

  for (int i = 0; i < reserve.size(); i++) {
    for (int j = 0; j < lost.size(); j++) {
      if ((abs(reserve[i] - lost[j]) == 1) && lost[j] != 0 && reserve[i] != 0) {
        lost[j] = 0;
        reserve[i] = 0;
        answer++;
        break;
      }
    }
  }
  return answer;
}