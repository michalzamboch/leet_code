#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int> arg)
{
	for (auto i : arg)
	{
		cout << i << " ";
	}
	cout << endl;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto nums1Size = nums1.size();
        auto nums2Size = nums2.size();

        if (nums1Size + nums2Size == 0)
        {
        	return 0.0;
        }

        vector<int> resultNums;

        int index1 = 0;
        int index2 = 0;
        
        while (index1 < nums1Size && index2 < nums2Size)
        {
        	if (nums1.at(index1) < nums2.at(index2))
        	{
        		resultNums.push_back(nums1.at(index1));
        		index1++;
        	}
        	else
        	{
        		resultNums.push_back(nums2.at(index2));
        		index2++;
        	}
        }

        for (index1; index1 < nums1Size; index1++)
        {
        	resultNums.push_back(nums1.at(index1));
        }

        for (index2; index2 < nums2Size; index2++)
        {
    		resultNums.push_back(nums2.at(index2));
        }

        if (resultNums.size() == 1)
        {
        	return (double)resultNums.at(0);
        }

        return median(resultNums);
    }

    double median(std::vector<int>& arr)
    {
    	double med = 0.0;
    	int middle = arr.size() / 2;

    	if (arr.size() % 2 == 0)
    	{
    		med = (arr.at(middle - 1) + arr.at(middle));
    		med /= 2;
    	}
    	else
    	{
    		med = (double)arr.at(middle);
    	}

    	return med;
    }
};

int main()
{
	vector<int> nums1{1, 3};
	vector<int> nums2{2};

	Solution solution;
	double res1 = solution.findMedianSortedArrays(nums1, nums2);
	cout << res1 << endl;

	vector<int> nums3{1, 2};
	vector<int> nums4{3, 4, 5, 5};

	Solution solution2;
	double res2 = solution2.findMedianSortedArrays(nums3, nums4);
	cout << res2 << endl;

	return 0;
}