#include <unordered_set>
#include <iostream>
#include <vector>

int solution(std::vector<int> nums)
{

    int size = nums.size();
    std::unordered_set<int> pocketMon;

    for (int i = 0; i < size; i++)
    {
        pocketMon.insert(nums[i]);
        }
    return std::min((int)pocketMon.size(), size / 2);
}

int main()
{
    std::vector<int> vector = {3, 3, 3, 2, 2, 4};
    int ans = solution(vector);
    std::cout << ans << std::endl;
}