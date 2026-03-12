
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

// Bit simulation
int add(int a, int b) {
    int result = 0;
    int carry = 0;

    for (int i = 0; i < 32; i++) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;

        int sum = bitA ^ bitB ^ carry;

        if (sum)
            result |= (1 << i);

        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry); // we are doing this because
        // Step 1: Look at All Possible Cases
        // bitA	bitB	carry_in	Sum	carry_out
        // 0	0	0	0	0
        // 0	0	1	1	0
        // 0	1	0	1	0
        // 0	1	1	0	1
        // 1	0	0	1	0
        // 1	0	1	0	1
        // 1	1	0	0	1
        // 1	1	1	1	1

        // Observe when carry_out = 1:

        // (1,1,0)

        // (1,0,1)

        // (0,1,1)

        // (1,1,1)

        // In all these cases at least two bits are 1.
        // Each pair that can produce a carry:

        // bitA & bitB

        // bitA & carry_in

        // bitB & carry_in
    }

    return result;
}