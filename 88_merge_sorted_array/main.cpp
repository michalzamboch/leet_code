#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0;
		int j = 0;
		vector<int> result;

		while (i < m && j < n)
		{
			if (nums1.at(i) <= nums2.at(j))
			{
				result.push_back(nums1.at(i));
				i++;
			}
			else
			{
				result.push_back(nums2.at(j));
				j++;
			}
		}

		while (i < m)
		{
			result.push_back(nums1.at(i));
			i++;
		}

		while (j < n)
		{
			result.push_back(nums2.at(j));
			j++;
		}

		nums1.clear();
		nums1 = result;
	}
};

int main(int argc, char const *argv[])
{

	return 0;
}