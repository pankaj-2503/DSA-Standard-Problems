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


void build(int ind,int low,int high){ // here low and high are the range of the array a[],while ind is the index of the segment tree
    // here we are using 2*ind+1 and 2*ind+2 to find the left and right child of the segment tree
    // base case
    if(low==high){
        seg[ind]=a[low];
        return;
    }

    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);


}
int query(int ind,int low,int high,int l,int r){ // here low and high are the range of the array a[],while ind is the index of the segment tree 
    // l and r are the range of the query

    //completely lies within range
    if(low>=l && high<=r) return seg[ind];
    // doesn't lie
    if(high<l || low>r) return INT_MIN;
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return max(left,right);
}

v-oid update(int ind,int low,int high,int pos,int value){ // here low and high are the range of the array a[],while ind is the index of the segment tree
    // l and r are the range of the query 
    
    if(low==high) {
        seg[ind]+=value;
    }
    else {
        int mid=(low+high)/2;
        if(pos<=mid){
            update(2*ind+1,low,mid,pos,value);
        }else{
            update(2*ind+2,mid+1,high,pos,value);
        }
        // for updating values for finding sum in range
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
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