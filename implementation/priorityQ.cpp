#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 입력 속도 향상
    cin.tie(nullptr);            // 입력 속도 향상

    int N;
    cin >> N;

    // 최소 힙을 사용하여 N번째로 큰 수를 찾기
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // 배열의 모든 원소를 입력받음
    for (int i = 0; i < N * N; i++)
    {
        int num;
        cin >> num;

        if (minHeap.size() < N)
        {
            minHeap.push(num); // 힙의 크기가 N보다 작으면 그냥 추가
        }
        else if (minHeap.top() < num)
        {
            minHeap.pop();     // N번째 큰 값을 유지하기 위해 가장 작은 값을 제거
            minHeap.push(num); // 새로운 값 추가
        }
    }

    // 최소 힙의 루트가 N번째 큰 수
    cout << minHeap.top() << endl;

    return 0;
}
