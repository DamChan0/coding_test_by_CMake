#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 좌표 압축을 수행하는 함수
vector<int> compressVector(const vector<int> &v)
{
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    unordered_map<int, int> compressedMap;
    for (int i = 0; i < sorted.size(); i++)
    {
        compressedMap[sorted[i]] = i;
    }

    vector<int> compressed;
    compressed.reserve(v.size()); // 미리 크기 예약
    for (int value : v)
    {
        compressed.push_back(compressedMap[value]);
    }
    return compressed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> compressedList(M);
    for (int i = 0; i < M; i++)
    {
        vector<int> arr(N);
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j]; // 원래 좌표를 입력받음
        }
        // 압축된 좌표 배열을 생성
        compressedList[i] = compressVector(arr);
    }

    int matchCnt = 0;
    // 중복된 행 찾기
    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            if (compressedList[i] == compressedList[j])
                matchCnt++;
        }
    }

    cout << matchCnt << '\n';
    return 0;
}
