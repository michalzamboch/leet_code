#include <iostream>
#include <cmath>
#include <limits>

// clear && g++ main.cpp && time ./a.out

class Solution {
public:
    int reverse(int x) {
        unsigned int tempResult = 0;
        bool negative = x < 0;
        x = std::abs(x);

        while (x > 0)
        {
            auto temp = x % 10;
            tempResult += temp;
            if (x > 10)
            {
                tempResult *= 10;
            }
            
            x /= 10;
        }

        int result = (int)tempResult;
        if (negative == true)
        {
            result *= -1;
        }
        
        return (signed int)result;    
    }
};

int main()
{
    auto *s = new Solution();
    
    std::cout << s->reverse(964632435) << std::endl;

    delete s;
    return 0;
}