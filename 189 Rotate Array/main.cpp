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

// clear && g++ -Wall main.cpp && time ./a.out

void print(bool x)
{
    cout << (x ? "true" : "false") << endl;
}

void print(vector<int> s)
{
    cout << "[ ";
    for (auto x : s) {
        cout << x << " ";
    }
    cout << "]" << endl;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> temp{nums};

        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[nums.size() - k + i];
        }

        for (int i = k; i < (int)nums.size(); i++)
        {
            nums[i] = temp[i - k];
        }
        print(temp);
        print(nums);
    }
};

int main()
{
    vector<int> arr{1,2,3,4,5,6,7};
    int k = 3;
    vector<int> arr2{-1,-100,3,99};
    int l = 2;
    vector<int> arr3{1,2,3};
    int m = 2;

    auto s = new Solution();
    s->rotate(arr, k);
    s->rotate(arr2, l);
    s->rotate(arr3, m);
    
    return 0;
}
