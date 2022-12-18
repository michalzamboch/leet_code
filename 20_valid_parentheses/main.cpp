#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> arg)
{
    for (auto i : arg)
    {
        cout << i << " ";
    }
    cout << endl;
}

class Solution
{
public:
    bool isValid(string s)
    {
        if (s == "")
        {
            return true;
        }
        if (s.length() == 1 && isBracket(s.at(0)))
        {
            return false;
        }

        stack<char> open;

        for (const char c : s)
        {
            if (isOpen(c))
            {
                open.push(c);
                continue;
            }

            if (isClosed(c))
            {
                if (open.size() <= 0)
                {
                    return false;
                }

                char openC = open.top();
                if (isPair(openC, c) == false)
                {
                    return false;
                }
                else
                {
                    open.pop();
                }
            }
        }

        if (open.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
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

int main(int argc, char const *argv[])
{
    string s1 = "(4564c5d64c5d6s4c5d6(((s4c56ds4([]))123456}789123456789";
    string s2 = "()[]{}";

    Solution solution;
    cout << s1 << endl;
    auto res1 = solution.isValid(s1);
    printBool(res1);

    return 0;
}