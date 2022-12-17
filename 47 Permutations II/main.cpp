#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

// clear && g++ -Wall main.cpp && time ./a.out

template <typename T>
void print(vector<T> arg)
{
    cout << "{ ";
    for (auto i : arg)
    {
        cout << i << " ";
    }
    cout << "}" << endl;
}

void print(bool b)
{
    cout << (b ? "true" : "false") << endl;
}

void print(vector<vector<int>> v)
{
    for (auto i : v)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());

        do
        {
            v.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return v;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> x1{1, 1, 2};
    vector<int> x2{1, 2, 3};
    auto s = new Solution();

    auto res = s->permuteUnique(x2);
    print(res);

    return 0;
}