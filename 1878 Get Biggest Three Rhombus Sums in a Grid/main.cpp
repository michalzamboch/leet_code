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

void print(set<int, greater<int>> s)
{
    cout << "[ ";
    for (auto x : s) {
        cout << x << " ";
    }
    cout << "]" << endl;
}

void print(vector<int> s)
{
    cout << "[ ";
    for (auto x : s) {
        cout << x << " ";
    }
    cout << "]" << endl;
}

void print(vector<vector<int>> vv)
{
    cout << ">>>" << endl;
    for (auto v : vv) {
        print(v);
    }
    cout << "<<<" << endl;
}

// ----------------------------------------------------------

class Solution {
public:
    set<int, greater<int>> biggestNums;
   
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        for (int i = 0; i < (int)grid.size(); i++)
        {
            for (int i = 0; i < (int)grid.size(); i++)
            {
                
            }
        }

        return vector<int>{0,0,0};
    }
    
    

    vector<int> getResult()
    {
        vector<int> result;
        auto it = biggestNums.begin();
        int i = 0;
        while (i < 3 && it != biggestNums.end())
        {
            result.push_back(*it);
            i++;
            it++;
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> grid{{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    print(grid);

    auto sol = new Solution();
    auto res = sol->getBiggestThree(grid);
    print(res);

    return 0;
}
