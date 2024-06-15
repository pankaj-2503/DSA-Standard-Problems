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

bool isPrime(int n){
    int cnt=0;
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
           return false;
        }
    
    }
    return true;
}
int main()
{
    int n=342;
    cout<<isPrime(n);
    return 0;
}