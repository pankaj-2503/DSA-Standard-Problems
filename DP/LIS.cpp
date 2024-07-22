
// recursion + memoisation
class Solution {
public:
    // time complexity - O(N*N) , space complexity - O(N*N)+O(N) , recursion stack
    int getAns(vector<int>&nums, int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(nums, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || nums[ind] > nums[prev_index]) {
        take = 1 + getAns(nums, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
         
        return getAns(nums, n, 0, -1, dp);
    }
};


    // Tabulation approach : Time complexity - O(N*N) ,space complexity - O(N*N)
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];
}
// space optimisation -> space complexity -2*O(N)
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> next(n+1,0);
    
    vector<int> cur(n+1,0);
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + next[prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + next[ind+1];
            }
    
            cur[prev_index+1] = max(notTake,take);
        }
        next = cur;
    }
    
    return cur[0];
}

class Solution {
public:

    // Tabulation approach : Time complexity - O(N*N) ,space complexity - O(N)
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        // state : dp[i] -> represent how many times i'th number in array is greater than prefix of length i-1
        // transition: dp[i] -> dp[i-1],dp[i-2],dp[i-3]...dp[0]
        // base case : each of length 1 would be longest if considering that itself
        // final subproblem: max(dp[0],dp[1],...dp[n-1]);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

// Most efficient approach-> TC: O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int>lis;
        for(auto i:nums){
            if(lis.empty() || i>lis.back()){
                lis.push_back(i);
            }else{
                auto it=lower_bound(lis.begin(),lis.end(),i);
                *it=i;
            }
        }
        return lis.size();
    }
};