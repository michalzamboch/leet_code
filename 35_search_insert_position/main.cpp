#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
    	if (nums.size() == 0)
    	{
    		return 0;
    	}
    	
        return myBinSearch(nums, 0, nums.size() - 1, target);
    }
    
    int myBinSearch(vector<int>&nums, int l, int r, int target)
    {
    	if (l <= r)
    	{
    		int mid = l + (r - l) / 2;

    		if (nums.at(mid) == target)
    		{
    			return mid;
    		}
    		else if (nums.at(mid) > target)
    		{
    			return myBinSearch(nums, l, mid - 1, target);
    		}

    		return myBinSearch(nums, mid + 1, r, target);
    	}

    	//cout << "l: " << l << ", r: " << r << endl;
    	return l;
    }
};

int main(int argc, char **argv)
{
	vector<int> x{1,3,5,6};
	int target = 7;

	Solution solution;
	int res = solution.myBinSearch(x, 0, x.size() - 1, target);
	cout << "res: " << res << endl;

	return 0;
}