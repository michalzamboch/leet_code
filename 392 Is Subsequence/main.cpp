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
#include <optional>

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
    // s - sub string, t - full string
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
        {
            return true;
        }

        int is = 0, it = 0;

        while (it < t.length())
        {
            if (t.at(it) == s.at(is))
            {
                is++;
                if (is >= s.size())
                {
                    return true;
                }
            }
            it++;
        }

        return false;
    }
};

int main()
{
    string s = "abc";
    string t = "ahbgdc";

    Solution sol;
    auto res = sol.isSubsequence(s, t);
    print(res);

    return 0;
}
