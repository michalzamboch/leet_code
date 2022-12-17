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
    bool threeConsecutiveOdds(vector<int>& arr) {
        int counter = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            auto& num = arr.at(i);
            if (odd(num) && counter < 3)
            {
                counter++;
                if (counter >= 3)
                {
                    return true;
                }

            }
            else if (!odd(num) && counter < 3)
            {
                counter = 0;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    bool odd(int num)
    {
        return (num % 2) == 1; 
    }
};

int main()
{
    vector<int> v1{2,6,4,1};
    vector<int> v2{1,2,34,3,4,5,7,23,12};
    vector<int> v3{1,1,1};
    Solution s;
    
    auto r1 = s.threeConsecutiveOdds(v1);
    print(r1);

    auto r2 = s.threeConsecutiveOdds(v2);
    print(r2);
    auto r3 = s.threeConsecutiveOdds(v3);
    print(r3);

    return 0;
}