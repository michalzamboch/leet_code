#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_map>
#include <utility>

using namespace std;

// clear && g++ -Wall main.cpp && time ./a.out

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

void print(bool b)
{
    cout << (b ? "true" : "false") << endl;
}

void print(int i, char c, string msg)
{
    cout << i << ". " << c << " " << msg << endl;
}

class Solution
{
public:
    stack<char> open;
    stack<char> closed;
    stack<pair<int, char>> brackets;
    int index = 0;

    bool isOpen(const char c)
    {
        return (c == '[' || c == '(' || c == '{');
    }

    bool isClosed(const char c)
    {
        return (c == ']' || c == ')' || c == '}');
    }

    bool isBracket(const char c)
    {
        return (isClosed(c) || isOpen(c));
    }

    bool isPair(const char c1, const char c2)
    {
        cout << c1 << ":" << c2 << endl;
        return ((c1 == '[' && c2 == ']') || (c1 == ']' && c2 == '[')) ||
               ((c1 == '(' && c2 == ')') || (c1 == ')' && c2 == '(')) ||
               ((c1 == '{' && c2 == '}') || (c1 == '}' && c2 == '{'));
    }

    void findStart(string s)
    {
        while (index < s.length())
        {
            if (isClosed(s.at(index)))
            {
                index++;
            }
            else
            {
                break;
            }
        }
    }

    char topC()
    {
        return brackets.top().second;
    }

    int topI()
    {
        return brackets.top().first;
    }

    void pop()
    {
        return brackets.pop();
    }

    void push(int i, char c)
    {
        brackets.push({i, c});
    }

    bool empty()
    {
        return brackets.empty();
    }

    int longestValidParentheses(string s)
    {
        int maxans = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxans = max(maxans, i - st.top());
                }
            }
        }
        return maxans;
    }
};

int main(int argc, char const *argv[])
{
    string s2 = "()(()";

    Solution solution;
    cout << s2 << endl;
    auto res1 = solution.longestValidParentheses(s2);
    cout << "result: " << res1 << endl;

    return 0;
}