#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> cables(k);
    int max_length = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> cables[i];
        if (cables[i] > max_length)
            max_length = cables[i];
    }

    long long left = 1, right = max_length;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2; // 중간값 계산 방식 변경
        long long count = 0;

        for (int i = 0; i < k; i++)
        {
            count += cables[i] / mid;
        }

        if (count < n)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << right << endl; // 최종적으로 right가 정답
    return 0;
}
