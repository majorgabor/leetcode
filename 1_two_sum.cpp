#include <iostream>
#include <vector>
#include <map>
#include "my_utils.h"

std::vector<int> twoSum(std::vector<int> &nums, int target)
{

    std::map<int, int> seen{{target - nums[0], 0}};

    for (int i = 1; i < nums.size(); i++)
    {
        if (auto it = seen.find(nums[i]); it != seen.end())
        {
            return {it->second, i};
        }
        seen.insert({target - nums[i], i});
    }
    return {0, 0};
}

int main()
{
    int t{9};
    std::vector<int> n{2, 7, 11, 15};
    std::cout << "nums: " << n <<" target: " << t << " -> output: " << twoSum(n, t) << std::endl;

    t = 6;
    n = {3,2,4};
    std::cout << "nums: " << n <<" target: " << t << " -> output: " << twoSum(n, t) << std::endl;

    t = 6;
    n = {3,3};
    std::cout << "nums: " << n <<" target: " << t << " -> output: " << twoSum(n, t) << std::endl;

    return 0;
}