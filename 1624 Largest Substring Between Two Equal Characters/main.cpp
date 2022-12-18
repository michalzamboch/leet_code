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

void print(unordered_map<char, set<int>> umap)
{
    for (auto it = umap.begin(); it != umap.end(); ++it)
    {
        cout << it->first << ": ";
        for (auto i : it->second)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    unordered_map<char, set<int>> chars;

    int maxLengthBetweenEqualCharacters(string s)
    {
        int res = -1;
        for (auto i = 0; i < s.length(); i++)
        {
            insert(s.at(i), i);
        }

        for (auto &x : chars)
        {
            if (x.second.size() >= 2)
            {
                res = max(res, getDiff(x.second));
            }
        }

        return res;
    }

    int getDiff(set<int> v)
    {
        auto x = --v.end();
        return abs(*v.begin() - *x) - 1;
    }

    void insert(char c, int i)
    {
        auto present = chars.find(c);
        if (present == chars.end())
        {
            chars.insert({c, {i}});
        }
        else
        {
            chars[c].insert(i);
        }
    }
};

int main()
{

    string s2 = "mgntdygtxrvxjnwksqhxuxtrv";

    Solution solution;
    cout << s2 << endl;
    auto res1 = solution.maxLengthBetweenEqualCharacters(s2);
    cout << "result: " << res1 << endl;

    return 0;
}