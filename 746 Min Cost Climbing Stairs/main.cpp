#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> s)
{
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b, result = 0;
        for (int &c : cost) {
            b = a;
            a = c + result;
            result = min(a, b);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> v1{10,15,20};

    print(v1);
    auto r1 = s.minCostClimbingStairs(v1);
    cout << r1 << endl;

    return 0;
}
