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

vector<int>findDivisors(int n){
    vector<int>divisors;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            divisors.pb(i);
            if(n/i!=i){
                divisors.pb(n/i);
            }
        }
    }
    return divisors;
}

int main()
{
    int n;cin>>n;
    vector<int>result=findDivisors(n);
    return 0;
}