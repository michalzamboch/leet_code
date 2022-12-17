#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// clear && g++ main.cpp && time ./a.out  

void printBool(bool b)
{
    if (b)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

void printInterval(string s, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}


class Solution {
public:
    enum State{loading, unloading};
    
    std::unordered_map<char, int> temp;
    int maximum = 0;
    
    string longestPalindrome(string s) {
        string result = "";
        State state = loading;
        
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

        return result;
    }

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

    bool isPaLid(string s, int start, int end)
    {
        int i = start;
        int mid = (start + end) / 2;

        while (start <= mid)
        {
            if (s.at(start) != s.at(end))
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    string makeString(string s, int start, int end)
    {
        string res = "";
        for (int i = start; i <= end; i++)
        {
            res += s.at(i);
        }
        return res;
    }
};

int main()
{
    string s = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";

    Solution solution;
    auto res = solution.longestPalindrome(s);

    cout << res << endl;

	return 0;
}