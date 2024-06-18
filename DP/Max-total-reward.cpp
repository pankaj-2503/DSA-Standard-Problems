class Solution {
public:
    // time complexity - O(N*9000) , space complexity - O(N*9000);
    int solve(vector<int>&a ,int index,int sum,int n,vector<vector<int>>&dp){
         if(index>=n){
            return sum;
         }
         if(dp[index][sum]!=-1) return dp[index][sum];
         int take=0;
         if(a[index]>sum){
          take=solve(a,index+1,sum+a[index],n,dp);
         }
         int nottake=solve(a,index+1,sum,n,dp);
         return dp[index][sum]=max(take,nottake);
         
    }
    int maxTotalReward(vector<int>& a) {
        int n=a.size();
        
        vector<vector<int>>dp(n+1,vector<int>(9000,-1));
        sort(a.begin(),a.end());
        return solve(a,0,0,n,dp);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();