#include <bits/stdc++.h>
using namespace std;
 
// Function to divide a by b and
// return floor value of the result

// Time complexity : O(a/b)
class Solution {
public:
    int divide(int dividend, int divisor) {
    long long a=dividend,b=divisor;
       if(a == INT_MIN && b == -1)
        return INT_MAX;
  
    // The sign will be negative only if sign of 
    // divisor and dividend are different
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;

    // remove sign of operands
    a = abs(a);
    b = abs(b);

    // Initialize the quotient
    long long quotient = 0;

    // Iterate from most significant bit to 
    // least significant bit
    for (int i = 31; i >= 0; --i) {

        // Check if (divisor << i) <= dividend
        if ((b << i) <= a) {
            a -= (b << i);
            quotient |= (1LL << i);
        }
    }

    return sign * quotient;
    }
};


// Most optimised approach
// Basic Idea : a/b = e ln(a) / e ln(b) = e( ln(a) – ln(b) )

// Time complexity - O(Log(a))
long long int divide(long long int dividend, long long int divisor)
{
    if (dividend == 0)
        return 0;
    if (divisor == 0)
    {
        cout << "Division by 0 is impossible\n";
        return 0;
    }
 
    
    long long int sign = (dividend < 0) ^ (divisor < 0);
 
    // abs() : function used to get the absolute values
    dividend = abs(dividend);
    divisor = abs(divisor);
    if (divisor == 1)
        return ((sign == 0) ? dividend : -dividend);
 
    
    // since property of log -> log(a) - log(b) = log(a/b) and exp is e^(log(a/b))
    long long int ans = exp(log(dividend) - log(divisor)) + 0.0000000001;
    /*
     adding 0.0000000001 to compensate for the precision errors
     like for a = 18 and b = -6,
     result after exponentiation will be 2.999999999...
     adding 0.0000000001, sets it right
    */
    return ((sign == 0) ? ans : -ans);
}