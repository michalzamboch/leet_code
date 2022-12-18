#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

template <typename T>
void print(std::vector<T> arg)
{
    for (auto i : arg)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int begin = 0, end = 0, farthest = 0;
        int jumps = 0;

        for (int i = 0; i < (nums.size() - 1); i++)
        {
            farthest = max(farthest, i + nums.at(i));

            if (i == end)
            {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{2, 3, 1, 1, 4};
    vector<int> nums2{2, 3, 0, 1, 4};
    vector<int> nums3{1, 2};

    Solution solution;
    auto result = solution.jump(nums3);
    cout << "result: " << result << endl;

    return 0;
}