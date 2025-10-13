
a=10,b=30
a -> 001010
b -> 011110
a+b without carry -> 010100 (same as a^b)
a+b carry         -> 010100 (same as (a&b)<<1 )


// function to add two numbers without using arithmetic operators
int sum(int a, int b) {
    
    // Iterate till there is no carry 
    while (b != 0) { 
        
        // carry contains common set bits of a and b, left shifted by 1
        int carry = (a & b) << 1;

        // Update a with (a + b without carry)
        a = a ^ b;
      
        // Update b with carry
        b = carry; 
    } 
    return a;
} 