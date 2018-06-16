#include <iostream>

class Solution {
public:
    int reverse(int x) {
        bool negative(false);
        int tmp(x);
        if (x < 0) {
            negative = true;
            tmp = abs(x);
        }
    
        int result(0);
        while (tmp > 0) {
            
            if (result > (INT_MAX - tmp % 10) / 10) {
                result = 0;
                break;
            }
            
            result *= 10; 
            result += (tmp % 10);
            tmp /= 10; 
        }   
    
        if (result !=0 && negative)
            result = -result;

        std::cout<<result<<std::endl;    
        return result;
    }   
};

int main()
{
    Solution s;
    s.reverse(123);
    s.reverse(-123);
    return 0;
}
