#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

void print(vector<int> &digits)
{
    cout << "{ ";
    for (auto x : digits)
    {
        cout << x << " ";
    }
    cout << "}" << endl;
}

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int maxIndex = digits.size() - 1;
        digits.at(maxIndex) += 1;
        digits.insert(digits.begin(), 0);

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits.at(i) >= 10)
            {
                auto zbytek = digits.at(i) % 10;
                auto posun = digits.at(i) - zbytek;
                posun /= 10;

                if (i == 0 && posun > 1)
                {
                    digits.insert(digits.begin(), posun);
                    maxIndex++;
                    i = 1;
                }
                else
                {
                    digits.at(i - 1) += posun;
                    digits.at(i) = zbytek;
                }
            }
        }

        if (digits.at(0) == 0)
        {
            digits.erase(digits.begin());
        }

        return digits;
    }
};

int main(int argc, char const *argv[])
{

    Solution solution;

    vector<int> digits{9, 9, 9, 5, 9};
    print(digits);

    auto result = solution.plusOne(digits);
    print(result);

    return 0;
}