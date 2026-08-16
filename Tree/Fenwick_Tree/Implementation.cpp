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

