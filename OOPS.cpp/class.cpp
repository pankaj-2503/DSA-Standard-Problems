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

class Solve{
    
    public:
    int n,m;
    vector<int>rowSeats;
    Solve(int n,int m){
        this->n=n;
        this->m=m;
        vector<int>rowSeats(n,m);
    }

    string BookSeats(int rowNo,int seats){
        string p="Book seats from position";
        string q="Seats not available";

        if(rowSeats[rowNo]<=seats){
            rowSeats[rowNo]-=seats;
            return p;
        }else{
            return q;
        }
    }


};
int main()
{
    int n,m;cin>>n>>m;
    int q;cin>>q;

    Solve srt(2,3);
    while(q--){
        int r,s;
        cout<<srt.BookSeats(r,s);
    }
    return 0;
}