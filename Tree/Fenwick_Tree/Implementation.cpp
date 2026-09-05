#include<bits/stdc++.h>

using namespace std;

// Concepts


// bit[i] -> stores the sum of range of actual array like [1,8],[2,4] , also as size of array could be greater then we need compression of index as array have limited size
// what to find right most set bit -> i&-i  where -i is calculated using 2's complement which is 1+(~i), so unset the rightmost setbit we do x-=(x&-x)
// here bit[i] calculates sum from range j+1 to i where j is i-(i&-i)
// when we are building fenwick tree we are basically adding array part which is common for other ranges also , like which is contributing to other range eg. bit[1]=sum(1,4) , bit[8]=sum(4,8) then arr[4] is contributing to both partial_sort
// for finding sum(1,13)= bit[13]+bit[12]+bit[8] as each one would be holding sum of range (13,13) , (9,12) , (1,8) respectively which is nothing but while i>0 , i-=(i&-i)
// similarly for update we would go and update the part which is contributing to other range also using the same i+(i&-i)

// TC -> update - O(logN) , sum - O(logn) ,build - O(NlogN)

class FenwickTree{
    private:
        vector<long long>bit;
        int n;
    public:
        FenwickTree(int size=0):n(size),bit(size+1,0){}

        void build(vector<long long>&arr){
            n=arr.size();
            bit.assign(n+1,0);

            // O(N ) build
            for(int i=1;i<=n;i++){
                bit[i]+=arr[i-1];
                int j=i+(i&-i);
                if(j<=n) bit[j]+=bit[i];
            }
        }

        // point update at index i by delta
        void update(int i,int delta){
            for(;i<=n;i+=i&-i) bit[i]+=delta;
        }

        // prefix sum from 1 to idx
        long long sum(int idx){
            long long res=0;
            for(;idx>0;idx-=idx&-idx) res+=bit[idx];
            return res;
        }

        // Range sum from l to r
        long long range(long long l,long long r){
            return sum(r)-sum(l-1);
        }


};


// One solved problem used above method
// where problem asked this Given an array of n integers,
//  your task is to process q queries of the form: what is the sum of values in range [a,b]?

// Constraints

// 1 <= n,q <= 10^5
// 1 <= x_i <= 10^9
// 1 <= a <= b <= n

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;cin>>n>>q;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    FenwickTree ft;
    ft.build(a);

    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        cout<<ft.range(a,b)<<"\n";
    }
    return 0;
}



// Given an array of n integers, your task is to process q queries of the following types:

// update the value at position k to u
// what is the sum of values in range [a,b]?

// Input:

// 8 4
// 3 2 4 5 1 1 5 3
// 2 1 4
// 2 5 6
// 1 3 1
// 2 1 4
// Output:

// 14
// 2
// 11


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        // cout<<fixed<<setprecision(10);
        #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
        #endif


    ll n,q;cin>>n>>q;

    vi v(n);
    f(i,0,n) cin>>v[i];

    FenwickTree ft;
    ft.build(v);

    while(q--){
    ll type,a,b;
    cin>>type>>a>>b;

    if(type==2){
        cout<<ft.range(a,b)<<en;
    }else{
        ll delta=b-v[a-1];
        ft.update(a,delta);
        v[a-1]=b;
    }
    }



    return 0;
}



// using atcoder prebuilt function #include<atcoder/all>l  , but it won't work on online compiler like codeforces so use full implementation


#include <atcoder/all> // Include ACL's Fenwick Tree



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Initialize the Fenwick Tree with size n.
    fenwick_tree<ll> fw(n);

    // Build the tree by adding the initial values.
    for (int i = 0; i < n; i++) {
        fw.add(i, v[i]);
    }

    while (q--) {
        ll type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            // Update query: position 'a' (1-indexed) becomes 'b'.
            // Convert 'a' to 0-indexed.
            int idx = a - 1;
            ll delta = b - v[idx];
            v[idx] = b;
            fw.add(idx, delta); // ACL uses 0-indexed positions.
        } else {
            // Sum query: range [a, b] (1-indexed).
            // Convert to half-open interval [a-1, b) for ACL's sum function.
            cout << fw.sum(a - 1, b) << en;
        }
    }

    return 0;
}




// Inversion count  - Given an array of integers arr[]. You have to find the Inversion Count of the array. Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

class ft{
    private:
    vector<int>bit;
    int n;
    public:
     ft(int size=0):n(size),bit(size+1,0){}

     void update(int i,int delta){
         for(;i<=n;i+=(i&-i)) bit[i]+=delta;
     }
     int sum(int i){
         int ans=0;
         for(;i>0;i-=(i&-i)) ans+=bit[i];
         return ans;
     }
};
class Solution {
  public:

    int inversionCount(vector<int> &arr) {
        // code here
        int n=arr.size();

        //index compression
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin()+1; // as fenwick tree array bit is 1 based
        }

        ft f(n+1);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            cnt+=f.sum(arr[i]-1);
            f.update(arr[i],1);
        }
        return cnt;

    }
};