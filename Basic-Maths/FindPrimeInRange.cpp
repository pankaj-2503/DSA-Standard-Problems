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

//time complexity- O(nloglogn)
// prime numbers in range [l,r]
//sieve of eratosthenes
int main()
{
    int n;cin>>n;
    vector<bool>is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=sqrt(n);i++){
       if(is_prime[i]){
        for(int j=i*i;j<=n;j+=i){
            is_prime[j]=false;
        }
       }
    }
    f(i,0,n){
        if(is_prime[i]==true) cout<<i<<' ';
    }
    cout<<en;

    return 0;
}