#include <vector>

using namespace std;

int countWays(vector<int>& numbers, int target, int index, int sum) {
    // 모든 숫자를 사용한 경우, 결과 값을 확인하여 타겟 넘버와 일치하는지 확인
    if (index == numbers.size()) {
        return sum == target ? 1 : 0;
    }
    
    // 현재 숫자를 더하는 경우와 빼는 경우를 각각 계산
    int add = countWays(numbers, target, index + 1, sum + numbers[index]);
    int subtract = countWays(numbers, target, index + 1, sum - numbers[index]);
    
    // 현재 숫자를 더하거나 빼는 모든 경우의 수를 합산하여 반환
    return add + subtract;
}

int solution(vector<int> numbers, int target) {
    return countWays(numbers, target, 0, 0);
}

int main(){
    vector<int> a = {1,1,1,1,1};
    int target = 3;
    return solution(a, target);

}