#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        auto result = returnRow(matrix, target);
        int end = 0;
        if (result == -1)
            return false;
        else
            end = binSearch(matrix.at(result), 0, matrix.at(result).size() - 1, target);

        return !(end == -1);
    }

    int binSearch(vector<int> &arr, int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return binSearch(arr, l, mid - 1, x);

            return binSearch(arr, mid + 1, r, x);
        }

        return -1;
    }


    int returnRow(vector<vector<int>> &matrix, int target)
    {
        auto delkaY = matrix.size();
        auto delkaX = matrix.at(0).size();

        if (target < matrix.at(0).at(0))
        {
            return -1;
        }
        if (target > matrix.at(delkaY - 1).at(delkaX - 1))
        {
            return -1;
        }

        return binSearchRow(matrix, 0, delkaY - 1, target);
    }

    int binSearchRow(vector<vector<int>> &matrix, int l, int r, int target)
    {
        auto delkaY = matrix.size();
        auto delkaX = matrix.at(0).size();
        
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (target >= matrix.at(mid).at(0) && target <= matrix.at(mid).at(delkaX - 1))
                return mid;

            if (target <= matrix.at(mid).at(0) && target <= matrix.at(mid).at(delkaX - 1))      // arr[mid] > target
                return binSearchRow(matrix, l, mid - 1, target);

            return binSearchRow(matrix, mid + 1, r, target);
        }

        return -1;
    }
};


int main(int argc, char **argv)
{
    vector<vector<int>> matrix{{1}, {3}};
    int target = 20;
    Solution solution;

    auto result = solution.searchMatrix(matrix, target);
    if (result)
        cout << "OK" << endl;
    else
        cout << "Not ok" << endl;

    return 0;
}