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





// Time Complexities:
// Tree Construction: O( n )
// Query in Range: O( Log n )
// Updating an element: O( Log n ).
// Auxiliary Space: O(2*N)

struct node{
    int sum;
    node(){
        sum=0;
    }
};
node t[4*200200];
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}
void build(int id,int l,int r){
    if(l==r){
        t[id].sum=0;return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
}
void update(int id,int l,int r,int pos,int val){
    if(pos<l || pos>r) return;
    if(l==r){
        t[id].sum+=val;return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id]=merge(t[2*id],t[2*id+1]);
}
node query(int id,int l,int r,int lq,int rq){
    if(lq>r || l>rq) return node();
    if(lq<=l && rq>=r) return t[id];
    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}


int main()
{
    int n,q;cin>>n>>q;
    int a[n];
    f(i,0,n) cin>>a[i];
    build(1,0,n-1);
    
    while(q--){
        int ch;cin>>ch;
        if(ch==1){
            int a,b,u;cin>>a>>b>>u;
            a--;b--;
            update(1,0,n-1,a,u);
            update(1,0,n-1,b+1,-u);
        }else{
            int k;cin>>k;
            k--;
            node ans=query(1,0,n-1,0,k);
            cout<<ans.sum+a[k]<<endl;
        }
    }
    return 0;
}
