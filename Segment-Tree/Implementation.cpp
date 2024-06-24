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

int a[100005],seg[4*100005];



// Time Complexities:
// Tree Construction: O( n )
// Query in Range: O( Log n )
// Updating an element: O( Log n ).
// Auxiliary Space: O(2*N)


void build(int ind,int low,int high){
    // base case
    if(low==high){
        seg[ind]=a[low];
        return;
    }

    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*index+2,mid+1,high);
    seg[ind]=max(seg[2*index+1],seg[2*inde])


}
int query(int ind,int low,int high,int l,int r){
    //completely lies within range
    if(low>=l && high<=r) return seg[ind];
    // doesn't lie
    if(high<l || low>r) return INT_MIN;
    int mid=(left+right)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*index+2,mid+1,high,l,r);
    return max(left,right);
}

int main()
{
    int n;cin>>n;
    f(i,0,n) cin>>a[i];
    build(0,0,n-1);
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<query(0,0,n-1,l,r);
    }
    return 0;
}