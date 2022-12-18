#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArray(const std::vector<T> array)
{
	cout << "[ ";
	for (auto x : array)
	{
		cout << x << " ";
	}
	cout << "]" << endl;
}

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> result{0, 0};

		printArray<int>(nums);

		for (auto id1 = 0; id1 < nums.size() - 1; id1++)
		{
			for (auto id2 = id1 + 1; id2 < nums.size(); id2++)
			{
				auto x = nums.at(id1) + nums.at(id2);
				cout << "x: " << x << " = " << nums.at(id1) << " + " << nums.at(id2) << endl;
				if (x == target)
				{
					result.at(0) = id1;
					result.at(1) = id2;
					return result;
				}
			}
		}

		return result;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums{3, 2, 4};
	int target = 6;
	/*
	[3,2,4]
	6
	*/

	Solution solution;

	auto result = solution.twoSum(nums, target);
	for (auto i : result)
	{
		cout << i << endl;
	}

	return 0;
}