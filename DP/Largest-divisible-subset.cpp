class Solution {
public:
// Time Complexity: O(N*N) , SC: O(N)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    hash[i]=j;
                    dp[i]=1+dp[j];
                }
            }
        }
        int ans=-1,lastIndex=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastIndex=i;
            }
        }

        vector<int>res;
        res.push_back(nums[lastIndex]);

        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            res.push_back(nums[lastIndex]);
        }
        reverse(res.begin(),res.end());

        return res;
    }
};