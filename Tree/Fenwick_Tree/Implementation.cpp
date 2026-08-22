#include<bits/stdc++.h>

using namespace std;

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



// using atcoder prebuilt function #include<atcoder/all>


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
