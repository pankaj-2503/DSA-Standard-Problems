// Using borrow method
int subtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a & b) << 1;
        a = a ^ b;
        b = borrow;
    }
    return a;
}

// Recursive
int subtract(int a, int b) {
    if (b == 0)
        return a;

    int diff = a ^ b;
    int borrow = (~a & b) << 1;

    return subtract(diff, borrow);
}

// Or
int subtract(int a, int b) {
    int result = 0;
    int borrow = 0;

    for (int i = 0; i < 32; i++) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;

        int diff = bitA ^ bitB ^ borrow;

        if (diff)
            result |= (1 << i);

        borrow = (~bitA & bitB) | (~(bitA ^ bitB) & borrow);
    }

    return result;
}

// 2's complement trick
a - b = a + (~b + 1)

int add(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int subtract(int a, int b) {
    return add(a, add(~b, 1));
}