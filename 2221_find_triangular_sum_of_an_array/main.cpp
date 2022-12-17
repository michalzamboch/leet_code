#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        return getResult(nums);
    }

    void print(vector<vector<int>> triangle)
    {
        for (auto y : triangle)
        {
            for (auto x : y)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    vector<int> createRow(vector<int> row)
    {
        if (row.size() <= 1)
            throw std::invalid_argument("Row must be bigger.");

        vector<int> generated(row.size() - 1);
        for (int i = 0; i < generated.size(); i++)
        {
            int tmp = row.at(i) + row.at(i + 1);
            tmp %= 10;
            generated.at(i) = tmp;
        }

        return generated;
    }

    int getResult(vector<int> &nums)
    {
        auto result = nums;

        for (int i = 1; i < nums.size(); i++)
        {
            auto newRow = createRow(result);
            result = newRow;
        }

        return result.at(0);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> x{1,2,3,4,5};
    Solution solution;
    auto res = solution.triangularSum(x);
    cout << "res: " << res << endl;

    return 0;
}