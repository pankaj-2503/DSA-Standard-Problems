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

//brute force
int findGcd(int n1, int n2) {
    
    
    for(int i = min(n1, n2); i > 0; i--) {
        
        if(n1 % i == 0 && n2 % i == 0) {
            // If i is a common factor,
            // return it as the GCD
            return i;
        }
    }
   

    return 1;
}

//optimal approach
int gcd(int a,int b){
    // based on euclid algorithm that if larger number is subtracted from smaller gcd of two no. remains same
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }else b=b%a;
    }
    if(a==0) return b;
    else return a;
}

int main()
{
    int a=10,b=35;
    cout<<gcd(a,b)<<en;
    return 0;
}