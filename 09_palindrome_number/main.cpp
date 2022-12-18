#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        string str1 = to_string(x);
        int delka = str1.length();
        int j = delka - 1;
        for (auto i = 0; i < delka; i++)
        {
            if (str1.at(i) != str1.at(j))
            {
                return false;
            }
            j--;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int x = 10;
    auto result = solution.isPalindrome(x);

    if (result)
        cout << "Ok" << endl;
    else
        cout << "Not ok" << endl;

    return 0;
}