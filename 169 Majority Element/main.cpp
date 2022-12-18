#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> umap;

    int majorityElement(vector<int> &nums)
    {
        for (auto &x : nums)
        {
            this->insert(x);
        }

        int biggestNum = this->umap.begin()->second;
        int biggestId = this->umap.begin()->first;

        for (auto &x : this->umap)
        {
            if (biggestNum < x.second)
            {
                biggestNum = x.second;
                biggestId = x.first;
            }
        }

        return biggestId;
    }

    void insert(int num)
    {
        if (this->umap.find(num) == this->umap.end())
        {
            // not found
            this->umap.insert({num, 1});
        }
        else
        {
            // found
            this->umap.at(num)++;
        }
    }
};

int main()
{
    return 0;
}
