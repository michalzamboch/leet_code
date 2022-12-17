#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    cout << "[ ";
    for (auto x : v)
        cout << x << " ";
    cout << "]" << endl;
}

void print(vector<vector<int>> v)
{
    for (auto x : v)
        print(x);
}

void print(bool b)
{
    cout << (b ? "true" : "false") << endl;
}

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end(), greater<int>());
        


    }
};

int main()
{
    vector<int> v1{2,7,4,1,8,1};

    Solution s;

    
    return 0;
}

