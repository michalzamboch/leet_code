#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
    	int pointer = s.length() - 1;
    	
    	while (s.at(pointer) == ' ')
    	{
    		pointer--;
    	}

    	int count = 0;
    	while (pointer >= 0)
    	{
    		if (s.at(pointer) != ' ')
    		{
	    		count++;
	    		pointer--;
    		}
    		else
    		{
    			break;
    		}
    	}

        return count;
    }
};

int main(int argc, char **argv)
{
	string s1 = "Hello world";
	string s2 = "   fly me   to   the moon  ";
	string s3 = "a";

	Solution solution;
	auto res = solution.lengthOfLastWord(s3);
	cout << "res: " << res << endl;
	
	return 0;
}