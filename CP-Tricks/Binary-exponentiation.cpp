#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define en endl
#define all(x) x.begin(),x.end()
#define f(i,from,to) for(ll i=from;i<to;i++)
#define fe(i,from,to) for(ll i=from;i<=to;i++)
#define fre(i,from,to) for(ll i=from;i>=to;i--)
#define fr(i,from,to) for(ll i=from;i>to;i--)
#define pb(x) push_back(x)
#define mx(v) *max_element(v.begin(), v.end())
#define mn(v) *min_element(v.begin(), v.end())
#define vi vector<ll>
#define vip vector<pair<ll,ll>>


// When we want to find pow(x,n) we could not direclty multiply n times as it would be time consuming instead we use binary exponentation
// 3^13= 3^(1101)=(3^8)*(3^4)*(3^1) , tc -> O(logn)

const ll mod=1e9+7;

// multiplicative inverse is calculated when a and b are co-prime , and fermet theorem is used which is nothing but binpow(a,b-2);
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long mulinv(ll a,ll b){
    return binpow(a,b-2); // calculated thorugh fermat theorem if b is non prime then extended euclidean algorithm is used ,which generally is not asked
}




// calculationg on ncr 
 const ll MOD=1e9+7;
     ll modExp(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    ll modInverse(ll x) {
        return modExp(x, MOD - 2);
    }

    ll calculate_nCr(int n, int r) {
        if (r < 0 || r > n) return 0;

        if (r > n - r) r = n - r;

        ll ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) % MOD;
            ans = ans * modInverse(i) % MOD;  // FIXED
        }

        return ans;
    }
int main()
{



    return 0;
}