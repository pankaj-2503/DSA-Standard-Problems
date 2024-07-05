//Recursion -> Time complexity - O(2^N) , space complexityk - O(N),recursion stack
class Solution {
public:
    bool solve(int index,vector<int>&nums,int target){
        if(target==0) return true;
        if(index==0) return nums[0]==target;
        
        bool notpick=solve(index-1,nums,target);
        bool pick=false;
        if(nums[index]<=target) pick=solve(index-1,nums,target-nums[index]);
        return pick||notpick;


    }
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2==1) return false;
        else{
           int k=sum/2;
           return solve(n-1,nums,k);
        }
       
    }
};


class Solution {
public:
//Memoisation -> Time complexity - O(n*sum)+O(N),for loop & space complexity - O(n*sum)+O(n),recursion stack
    bool solve(int index,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(index==0) return nums[0]==target;
        if(dp[index][target]!=-1) return dp[index][target];
        bool notpick=solve(index-1,nums,target,dp);
        bool pick=false;
        if(nums[index]<=target) pick=solve(index-1,nums,target-nums[index],dp);
        return dp[index][target] = pick || notpick;


    }

    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2==1) return false;
        else{
           vector<vector<int>>dp(n,vector<int>(sum+1,-1));
           int k=sum/2;
           return solve(n-1,nums,k,dp);
        }
       
    }
};

//Tabulation -> time complexity - O(n*k)+O(n), space complexity - O(n*k)
class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2==1) return false;
        else{
           int k=sum/2;
           vector<vector<bool>>dp(n,vector<bool>(k+1,false));
           //base case : if target sum is 0
           for(int i=0;i<n;i++){
            dp[i][0]=true;
           }
           if(nums[0]<=k) dp[0][nums[0]]=true;
           for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target){
                    pick=dp[i-1][target-nums[i]];
                }
                dp[i][target]=pick|| notpick;
            }
           }
           return dp[n-1][k];

        }
       
    }
};

// space optimisation
bool canPartition(int n, vector<int>& arr) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    else {
        int k = totSum / 2;

        // Create a vector to represent the previous row of the DP table
        vector<bool> prev(k + 1, false);

        // Base case: If the target sum is 0, it can be achieved by not selecting any elements
        prev[0] = true;

        // Initialize the first row based on the first element of the array
        if (arr[0] <= k)
            prev[arr[0]] = true;

        // Fill in the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            // Create a vector to represent the current row of the DP table
            vector<bool> cur(k + 1, false);
            cur[0] = true;

            for (int target = 1; target <= k; target++) {
                // Exclude the current element
                bool notTaken = prev[target];

                // Include the current element if it doesn't exceed the target
                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                // Update the current row of the DP table
                cur[target] = notTaken || taken;
            }

            // Set the current row as the previous row for the next iteration
            prev = cur;
        }

        // The final result is in the last cell of the previous row of the DP table
        return prev[k];
    }
}
