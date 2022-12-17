#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>

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
    int isValid(string s) {
        if (s == "")
        {
            return 0;
        }

        int pos = 0;
        vector<int>result;

        while (pos < s.length())
        {
            int x = this->isValid(s, pos);
            x *= 2;
            cout << "pos: " << pos << " -> " << x << endl;
            result.push_back(x);
        }
        print<int>(result);

        int max = maxElement(result);
        return 0;
    }

    int isValid(string s, int &pos)
    {
        stack<char> open;
        int count = 0;

        for (pos; pos < s.length(); pos++)
        {
            if (isOpen(s.at(pos)))
            {
                open.push(s.at(pos));
                continue;
            }

            if (isClosed(s.at(pos)))
            {
                if (open.empty())
                {
                    pos++;
                    break;
                }

                if (isPair(open.top(), s.at(pos)))
                {
                    open.pop();
                    count++;
                }
                else
                {
                    pos++;
                    break;
                }
            }
        }

        return count;
    }

    int maxElement(vector<int> x)
    {
        int max = x.at(0);

        for (auto i : x)
        {
            max = std::max(max, i);
        }

        return max;
    }

    bool isOpen(const char c)
    {
        if (c == '[' || c == '(' || c == '{')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isClosed(const char c)
    {
        if (c == ']' || c == ')' || c == '}')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isBracket(const char c)
    {
        return (isClosed(c) || isOpen(c));
    }

    bool isPair(const char c1, const char c2)
    {
        if (c1 == '[' && c2 == ']')
        {
            return true;
        }
        else if (c1 == '(' && c2 == ')')
        {
            return true;
        }
        else if (c1 == '{' && c2 == '}')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void printBool(bool b)
{
    if (b == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

vector<int> test()
{
    vector<int> a{1};
    vector<int> b{2};

    return a;
}

int main(int argc, char const *argv[])
{
    string s2 = "()()((([]))) 555  5 5 55 (()((([])))((([]))) 555 5  55 ";

    Solution solution;
    cout << s2 << endl;
    auto res1 = solution.isValid(s2);
    cout << res1 << endl;

    return 0;
}