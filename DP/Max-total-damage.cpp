// Input: power = [7,1,6,6]
// Output: 13
#define ll long long
class Solution {
public:
    // Time complexity - O(NlogN) , space complexity - O(N)
    long long maximumTotalDamage(vector<int>& power) {
        // we need map to store freq of each element bcz if we take one of them 
        // then we can take other of same value as no restriction ATQ
        
        sort(power.begin(),power.end());
        map<ll,ll>m;
        vector<pair<long,long>>v;
        for(auto i:power) m[i]++;
        for(auto i:m) v.push_back({i.first,i.second});
        ll n=v.size();
    
        // dp[i]-> max sum till ith index
        // transition dp[i]->max(dp[i-1],dp[j]+m[i].first*m[i]*second) here dp[j] represent 
        // max till jth index where we can take ith value , it is pick and notpick approach 
        vector<ll>dp(n+1);
        dp[0]=v[0].first*v[0].second;

        
        for(int i=1;i<v.size();i++){
             int j=i-1;
             // notpick
             dp[i]=dp[i-1];
             //pick
             while(j>=0 && v[i].first-v[j].first<=2) j--;
             ll key=v[i].first;
             ll val=v[i].second;
             if(j<0){
               
               dp[i]=max(dp[i],key*val);
             }
             else
             dp[i]=max(dp[i],dp[j]+key*val);
        }
        return dp[n-1];
    }
};
auto init=[](){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);
     return 'c';
};