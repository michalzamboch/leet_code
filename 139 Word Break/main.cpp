#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (auto &word : wordDict)
        {
            size_t ind = 0;
            while (true)
            {
                ind = s.find(word);
                if (ind != string::npos)
                    s.erase(ind, word.length());
                else
                    break;
            }
        }

        return s == "";
    }
};

void print(bool b)
{
    cout << (b ? "true" : "false") << endl;
}

int main()
{
    Solution s;
    cout << "App start..." << endl;

    vector<string> wordDict1{"aa", "ss"};
    string s1 = "aassaa";
    auto b = s.wordBreak(s1, wordDict1);
    print(b);

    wordDict1.clear();
    wordDict1 = {"car","ca","rs"};
    s1 = "cars";
    b = s.wordBreak(s1, wordDict1);
    print(b);

    return 0;
}
