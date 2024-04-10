#include <vector>
#include <iostream>
using namespace std;

// 전역변수 answer
int answer = 0;

void get_target_number(vector<int> numbers, int target, int sum, int index)
{
    // 종료 조건
    if (index == numbers.size())
    {
        if (sum == target)
        {
            answer++;
        }
        // 같지 않을때도 return
        return;
    }
    // 종료 조건이 만족되지않으면 계속 탐색
    cout << "더하기 시작 sum : " << sum << "index ;" << index << endl;
    get_target_number(numbers, target, sum + numbers[index], index + 1);
    cout << "더하기 끝  sum : " << sum << "index ;" << index << endl;
    cout << "빼기 시작 sum : " << sum << " index;" << index << endl;
    get_target_number(numbers, target, sum - numbers[index], index + 1);
    cout << "빼기 끝 sum : " << sum << " index:" << index << endl;
}

int solution(vector<int> numbers, int target)
{
    get_target_number(numbers, target, 0, 0);

    return answer;
}

int main()
{

    vector<int> a = {1, 1, 1, 1, 1};
    int target = 3;
    return solution(a, target);
}