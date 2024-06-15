// given a number reverse the number 
// eg. Input: 2343
//     Output: 3432
//     Input: -1234
//     Output: -4321

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

ll reverse(int n){
    ll ans=0;
    while(n){
        ans=ans*10+n%10;
        n/=10;
    }
    return ans;
}
int main()
{   
    int n=3434;
    cout<<reverse(n)<<en;
    return 0;
}