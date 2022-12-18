#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {

        uint32_t NO_OF_BITS = sizeof(n) * 8;
        uint32_t reverse_num = 0;
        int i;
        for (i = 0; i < NO_OF_BITS; i++)
        {
            if ((n & (1 << i)))
                reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
        }
        return reverse_num;
    }
};

int main()
{
    return 0;
}
