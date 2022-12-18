#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);

        for (int i = 2; i < rowIndex + 1; ++i)
            for (int j = 1; j < i; ++j)
                ans[i - j] += ans[i - j - 1];

        return ans;
    }
};

int main()
{
    return 0;
}
