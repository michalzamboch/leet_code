#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// clear && g++ main.cpp && time ./a.out

class Solution
{
public:
    std::unordered_map<char, int> temp;
    int maximum = 0;

    int lengthOfLongestSubstring(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.at(i);
            auto inserted = insert(c, i);

            if (inserted)
            {
                maximum = std::max(maximum, (int)temp.size());
            }
            else
            {
                i = temp[c];
                temp.clear();
            }
        }

        return maximum;
    }

    bool insert(char c, int i)
    {
        auto it = temp.find(c);
        if (it == temp.end())
        {
            temp.insert({c, i});
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution *s = new Solution();

    cout << "Result: " << s->lengthOfLongestSubstring("au") << endl;

    delete s;
    return 0;
}
