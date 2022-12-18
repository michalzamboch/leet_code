#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long int start = 0;
        long int end = x;
        
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            if (mid * mid == x) {
                return (int)mid;
            } else if (mid * mid < x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (end * end == x) {
            return (int)end;
        }
        return (int)start;
    }
};

int main()
{
    return 0;
}
