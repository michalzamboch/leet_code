#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        auto triangle = createTriangle(numRows);

        for (int y = 0; y < numRows; y++)
        {
            for (int i = 1; i < triangle.at(y).size() - 1; i++)
            {
                triangle.at(y).at(i) = triangle.at(y - 1).at(i - 1) + triangle.at(y - 1).at(i);
            }
        }

        return triangle;
    }

    void print(vector<vector<int>> triangle)
    {
        for (auto y : triangle)
        {
            for (auto x : y)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    vector<int> createRow(int count)
    {
        vector<int> row(count);
        fill_n(row.begin(), count, 1);
        return row;
    }

    vector<vector<int>> createTriangle(int count)
    {
        vector<vector<int>> triangle;
        for (int i = 1; i <= count; i++)
        {
            triangle.push_back(createRow(i));
        }

        return triangle;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    auto x = solution.generate(5);
    solution.print(x);

    return 0;
}