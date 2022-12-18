#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print(vector<T> arg)
{
    cout << "{ ";
    for (auto i : arg)
    {
        cout << i << " ";
    }
    cout << "}" << endl;
}

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        int index = 0;
        int count = 0;

        while (index < nums.size())
        {
            if (nums.at(index) != nums.at(count))
            {
                count++;
                nums.at(count) = nums.at(index);
            }

            index++;
        }

        count++;
        return count;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> x1{0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 5, 100};
    print<int>(x1);

    Solution solution;
    auto count = solution.removeDuplicates(x1);

    cout << "count: " << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << x1.at(i) << " " << endl;
    }

    return 0;
}