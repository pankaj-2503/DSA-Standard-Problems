class Solution {
public:
// TC: O(N*N), SC: 2*O(N)
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] && dp[i]==(1+dp[j])){
                    cnt[i]=cnt[i]+cnt[j];

                }
            }
        }
        int ans=0;
        int mx=*max_element(dp.begin(),dp.end());
        // cout<<mx<<endl;
        for(int i=0;i<n;i++){
            if(dp[i]==mx) ans+=cnt[i];
        }
        return ans;
    }
};