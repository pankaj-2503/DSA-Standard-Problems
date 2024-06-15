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

// from A-Z sheet striver

int main()
{  
   int n;cin>>n;

//1  
//    for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         cout<<"*";
//     }
//     cout<<en;
//    }
  
   
//    //2 
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<en;
//     }


    //   //3
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<j+1;
    //     }
    //     cout<<en;
    // }


    // //4
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<i+1;
    //     }
    //     cout<<en;
    // }

    // //5 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<"*";
    //     }
    //     cout<<en;4
    // }

    // //6
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<j+1;
    //     }
    //     cout<<en;
    // }
    

    // 7,8,9
    // for(int i=0;i<n;i++){
    //     int p=n-i;
    //     for(int j=0;j<p;j++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<2*i+1;k++) cout<<"*";
    //     for(int l=0;l<p;l++) cout<<" ";

    //     cout<<en;
    // }

    
    // for(int i=n-1;i>=0;i--){
    //     int p=n-i;
    //     for(int j=0;j<p;j++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<2*i+1;k++) cout<<"*";
    //     for(int l=0;l<p;l++) cout<<" ";

    //     cout<<en;
    // }


    // //10
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++) cout<<"*";
    //     cout<<en;
    // }
    // f(i,0,n){
    //     f(j,0,n-i-1) cout<<"*";
    //     cout<<en;
    // }

    
    // // 11 
    // for(int i=0;i<n;i++){
    //     int start=0;
    //     if(i%2==0) start=1;
    //     for(int j=0;j<=i;j++){
    //         cout<<start;
    //         start^=1;//toggling bits
    //     }
    //     cout<<en;
    // }

    // //12
    // for(int i=0;i<n;i++){
    //     int p=i+1;
    //     int q=(n-p)*2;
    //     for(int j=0;j<p;j++) cout<<j+1;
    //     for(int k=0;k<q;k++) cout<<" ";
    //     for(int l=0;l<p;l++) cout<<p-l;
    //     cout<<en;
    // }

    // // 13
    // int x=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //        cout<<x<<' ';x++;
    //     }
    //     cout<<en;
    // }

    // 14
    // for(int i=0;i<n;i++){
    //     char ch='A';
    //     for(int j=0;j<=i;j++){
    //        cout<<char(ch+j);
    //     }
       
    //     cout<<en;
    // }

    // //15
    // for(int i=0;i<n;i++){
    //     char ch='A';
    //     for(int j=0;j<n-i;j++) cout<<char(ch+j);
    //     cout<<en;
    // }

    //  //16
    // for(int i=0;i<n;i++){
    //     char ch='A';
    //     for(int j=0;j<=i;j++) cout<<char(ch+i);
    //     cout<<en;
    // }


    // //17
    // for(int i=0;i<n;i++){
    //     int p=n-i-1,q=2*i+1;
    //     for(int j=0;j<p;j++) cout<<" ";
    //     char ch='A';int k=0;
    //     for(k=0;k<i+1;k++) cout<<char(ch+k);
    //     k-=2;
    //     for(int m=0;m<q-i-1;m++) cout<<char(ch+k-m);
    //     for(int l=0;l<p;l++) cout<<" ";
    //     cout<<en;


    // }

    // 18
    // f(i,0,n){
    //     int start=n-i-1;
    //     fe(j,0,i){
    //         cout<<char('A'+start+j);
    //     }
    //     cout<<en;
    // }

    // // 19
    // f(i,0,n){
    //     f(j,0,n-i){
    //         cout<<"*";
    //     }
    //     f(l,0,2*i) cout<<" ";
    //     f(k,0,n-i){
    //         cout<<"*";
    //     }
    //     if(i!=n-1) cout<<en;
    // }
    //  fre(i,n,0){
    //     f(j,0,n-i){
    //         cout<<"*";
    //     }
    //     f(l,0,2*i) cout<<" ";
    //     f(k,0,n-i){
    //         cout<<"*";
    //     }
    //     cout<<en;
    // }

    // 20
    // f(i,0,n){
    //     int gap=2*(n-1)-2*i;
    //     fe(j,0,i){
    //         cout<<"*";
    //     }
    //     f(k,0,gap) cout<<" ";
    //     fe(l,0,i) cout<<"*";
    //     cout<<en;


    // }
    // f(i,0,n-1){
    //     f(j,0,n-i-1) cout<<"*";
    //     int gap=2*i+2;
    //     f(k,0,gap) cout<<" ";
    //     f(l,0,n-1-i) cout<<"*";
    //     cout<<en;
    // }

    // //21
    // f(i,0,n){
    //     f(j,0,n){
    //         if(i==0 || j==0 || (j==n-1) || (i==n-1)) cout<<"*";
    //         else cout<<" ";
    //     }
    //     cout<<en;
    // }
    
    // 22 
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int bottom=2*n-1-1-i;
            int right=2*n-1-1-j;
            cout<<n-min({top,left,right,bottom});
        }
        cout<<en;
    }


    


}