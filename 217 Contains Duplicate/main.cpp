#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <unordered_set>

using namespace std;

void print(bool x)
{
    cout << (x ? "true" : "false") << endl;
}

void print(unordered_set<int> s)
{
    cout << "[ ";
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << "]" << endl;
}

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        return usingUnorderedSet(nums);
    }

    bool usingSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size() - 1; i++)
        {
            if (nums.at(i) == nums.at(i + 1))
            {
                return true;
            }
        }

        return false;
    }

    bool usingUnorderedSet(vector<int> &nums)
    {
        unordered_set<int> res;
        for (auto x : nums)
        {
            res.insert(x);
        }

        return res.size() != nums.size();
    }
};

int main()
{
    vector<int> x1{1, 2, 3, 1};

    auto s = new Solution();
    auto res = s->containsDuplicate(x1);
    print(res);

    return 0;
}
