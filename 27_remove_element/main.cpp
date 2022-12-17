#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print(vector<T> arg)
{
    cout << "{ ";
    for (auto i : arg)
    {
        cout << i << " ";
    }
    cout << "}" << endl;
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto length = nums.size();
        if (length == 0)
        {
            return 0;
        }

    	int index = 0;
        int count = 0;

    	while (index < length)
    	{
            if (nums.at(index) != val)
            {
                nums.at(count) = nums.at(index);
                count++;
            }

    		index++;
    	}

    	return count;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> x1{0,1,2,2,3,0,4,2};
    int target = 2;
	print<int>(x1);

    Solution solution;
    auto count = solution.removeElement(x1, target);

    cout << "count: " << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << x1.at(i) << " " << endl;
    }

	return 0;
}