#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long int tmpResult = 0;
        long long int index = 1;
        bool negative = false;

        for (long long int i = s.length() - 1; i >= 0; i--)
        {
        	cout << i << ". " << s.at(i) << endl;

        	if (isNumber(s.at(i)))
        	{
        		int tmp = charToInt(s.at(i)) * index;
        		index *= 10;
        		tmpResult += tmp;
        	}
            else if (isLetter(s.at(i)) && tmpResult != 0)
            {
                return 0;
            }
        	else if (isNegative(s.at(i)))
        	{
        		negative = true;
        	}

            if (tmpResult > numeric_limits<int>::max())
            {
                break;
            }
        }
        
        cout << tmpResult << endl;
        
        if (negative)
        {
        	tmpResult *= (-1);
        }

        cout << tmpResult << endl;

        if (tmpResult > numeric_limits<int>::max())
        {
            return numeric_limits<int>::max();
        }
        else if (tmpResult < numeric_limits<int>::min())
        {
            return numeric_limits<int>::min();
        }
        else
        {
            return (int)tmpResult;
        }
    }

    bool isNumber(char c)
    {
    	if (c >= '0' && c <= '9')
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }

    bool isNegative(char c)
    {
    	if (c == '-')
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }

    bool isLetter(char c)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int charToInt(char c)
    {
    	return (int)(c - '0');
    }
};

int main(int argc, char const *argv[])
{

	Solution solution;

	string s1 = "-91283472332";
	int r1 = solution.myAtoi(s1);

	cout << r1 << endl;
    cout << "Melo by byt: -2147483648" << endl;

    cout << "max() " << numeric_limits<int>::max() << endl;
    cout << "min() " << numeric_limits<int>::min() << endl;

	return 0;
}