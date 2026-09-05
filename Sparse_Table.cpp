// A Sparse Table is a data structure designed for static range queries.
// When to Use a Sparse TableStatic/Immutable Data: The underlying array does not change (no updates, insertions, or deletions after precomputation).
// Idempotent Operations: The operation f(x, x) = x allows O(1) query execution.Range Minimum Query (RMQ) / Range Maximum Query (RMAQ)Range Greatest Common Divisor (GCD) / Least Common Multiple (LCM)Range Bitwise AND / ORAssociative Operations:
// For non-idempotent operations like Range Sum Query, it answers queries in $O(\log N)$ time instead of $O(1)$.
// Tree Queries (LCA): Frequently used in tree problems by converting Lowest Common Ancestor (LCA) queries to Range Minimum Queries via Eulerian Tour, or through direct binary lifting tables.
// Complexity Trade-offsPrecomputation Time: O(N \log N),Space Complexity: O(N \log N),Query Time: $O(1)$ for idempotent functions, O(\log N) for non-idempotent functions.


// By the same reasoning any interval can be uniquely represented as a union of intervals with lengths that are decreasing powers of two. E.g.  
// [2, 14] = [2, 9] U [10, 13] U [14, 14], where the complete interval has length 13, and the individual intervals have the lengths 8, 4 and 1 respectively. And also here the union consists of at most  
//  [log_2({length of interval})]  many intervals.


// //  Use sparse table only for finding range queries where sum,bitwise operation like xor,or , min,max,gcd,lcm is asked as there should be no updates in array

// Eg. 13 = (1101)2 = 8+4+1 , for a number x there can

#include<bits/stdc++.h>
using namespace std;


const int MAX_N = 2e5 + 5;
const int LOG = 25;

int a[MAX_N];       // Declared array a
int m[MAX_N][LOG];  // m[i][j] stores minimum in range [i, i + 2^j - 1]  , where i is index in array a, j is power of 2 length of array

int query(int l, int r) {
    int length = r - l + 1;
    int k = 0;
    // highest power of 2 which is less then length
    while ((1 << (k + 1)) <= length) {
        k++;
    }
    return min(m[l][k], m[r - (1 << k) + 1][k]);  // return min from subarray's with length of k
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;

    cin >> n>> q;


    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i]; // as length 2^0 =1 is a[i] itself
    }

    // Precomputing range minimums: O(N log N)
    for (int k = 1; k < LOG; k++) { // 2^25 would cover the range of n length array
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);  // finding minimum from 2 subarray each of length k , it's overlapping subproblem so previous length would be calculated earlier so constant time query
        }
    }


    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--; // Convert 1-based indexing to 0-based indexing
        cout << query(l, r) << "\n";
    }

    return 0;
}