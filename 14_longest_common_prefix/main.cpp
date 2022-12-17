#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.size() == 0)
        {
        	return "";
        }
        if (strs.size() == 1)
        {
        	return strs.at(0);
        }
    	
    	sort(strs.begin(), strs.end());
    	int shortestStr = shortest(strs);

        string first = strs.front();
        string last = strs.back();
        int i = 0;
        while (i < shortestStr && first.at(i) == last.at(i))
        	i++;

        string prefix = first.substr(0, i);
        return prefix;
    }

    string longestCommonPrefixOld(vector<string>& strs) {
        string prefix = "";

        if (strs.size() == 0)
        {
        	return "";
        }
        if (strs.size() == 1)
        {
        	return strs.at(0);
        }
    	
        int length = shortest(strs);
        for (int i = 0; i < length; ++i)
        {
        	char tmp = strs.at(0).at(i);
        	for (auto x : strs)
        	{
        		if (x.at(i) != tmp)
        		{
        			return prefix;
        		}
        	}

        	prefix += tmp;
        }

        return prefix;
    }

    int shortest(vector<string>& strs)
    {
    	int len = strs.at(0).length();
    	for (int i = 0; i < strs.size(); ++i)
    	{
    		int tmp = strs.at(i).length();
    		if (tmp < len)
    			len = tmp;
    	}

    	return len;
    }
};

int main()
{
	vector<string> strs1{"dog","racecar","car"};

	Solution solution;
	auto x = solution.longestCommonPrefix(strs1);

	cout << "\"" << x << "\"" << endl;
	return 0;
}