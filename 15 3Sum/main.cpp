#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

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

class Solution
{
public:
    vector<vector<int>> res;

    vector<vector<int>> threeSum(vector<int>& nums)
    {
         vector<vector<int>> res;

        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size();i++) {

            if((i > 0) && nums[i]==nums[i-1])
                continue;
            
            int l = i + 1; 
            int r = nums.size() - 1; 
            
            while (l < r) {
                
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum < 0)
                    l++;
                else if(sum > 0)
                    r--;
                else
                if(sum == 0) {
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                
                    while (l<r && nums[l] == nums[l+1]) 
                        l++;

                    while (l<r && nums[r] == nums[r-1]) 
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v{-1,0,1,2,-1,-4};
    vector<int> v2{0,0,0};
    vector<int> v3{0,1,1};
    
    Solution sol;
    auto res = sol.threeSum(v);
    cout << "----------------------" << endl;
    print(res);

    return 0;
}
