#include <bits/stdc++.h>
using namespace std;
 
// Function to divide a by b and
// return floor value of the result

// Time complexity : O(a/b)
long long divide(long long dividend, long long int divisor)
{
 
    // Calculate sign of divisor i.e.,
    // sign will be negative only if
    // either one of them is negative
    // otherwise it will be positive
    long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
    // Update both divisor and
    // dividend positive
    dividend = abs(dividend);
    divisor = abs(divisor);
 
    // Initialize the quotient
    long long quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }
 
    // Return the value of quotient with the appropriate
    // sign.
    return quotient * sign;
}


// another efficient way
// Function to divide a by b and
// return floor value it
long long divide(long long dividend, long long divisor) {
 
  // Calculate sign of divisor i.e.,
  // sign will be negative only if
  // either one of them is negative
  // otherwise it will be positive
  int sign = ((dividend < 0) ^ 
              (divisor < 0)) ? -1 : 1;
 
  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  // Initialize the quotient
  long long quotient = 0, temp = 0;
 
  // it checks if subtracting divisor from dividend still be Positive
  // then stores it in temp and it's means quotient would be set bit at i'th position
  for (int i = 31; i >= 0; --i) {
 
    if (temp + (divisor << i) <= dividend) {
      temp += divisor << i;
      quotient |= 1LL << i;
    }
  }
  //if the sign value computed earlier is -1 then negate the value of quotient
  if(sign==-1) quotient=-quotient;
   
  return quotient;
}


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