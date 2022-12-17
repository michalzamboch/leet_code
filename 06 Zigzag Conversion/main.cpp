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
    for (auto x : s) {
        cout << x << " ";
    }
    cout << "]" << endl;
}

class Solution {
public:
    string convert(string s, int numRows)
    {
        int cols = 0;
        int strLen = s.size();
        
        return "";
    }
};

int main()
{
    int rows = 3;
    string str = "PAYPALISHIRING"; 

    auto s = new Solution();
    
    return 0;
}
