class Solution{
    public:
    // Recursion - > Time complexity - O(2^N) , space complexity - O(N) -> recursion stack
    bool solve(int index,vector<int>&arr,int sum){
        
        if(sum==0) return true;
        if(index==0){
            if(arr[0]==sum) return true;
            return false;
        }
        
        bool pick=false;
        bool notpick=solve(index-1,arr,sum);
        if(arr[index]<=sum) pick=solve(index-1,arr,sum-arr[index]);
        
        return pick || notpick;
        
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        return solve(n-1,arr,sum);
    }
};

// Memoisation  -> Time complexity - O(n*sum) , space complexity - O(N*K)+O(N)
bool solve(int index,vector<int>&arr,int sum,vector<vector<int>>&dp){
        
        if(sum==0) return true;
        if(index==0){
            if(arr[0]==sum) return true;
            return false;
        }
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        bool pick=false;
        bool notpick=solve(index-1,arr,sum,dp);
        if(arr[index]<=sum) pick=solve(index-1,arr,sum-arr[index],dp);
        
        return dp[index][sum]=pick || notpick;
        
}

bool isSubsetSum(vector<int>arr, int sum){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    return solve(n-1,arr,sum,dp);
}


// Tabulation -> Time complexity - O(n*sum) , space complexity - O(N*K)

 bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        // base case -> if target sum is 0
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum){
            dp[0][arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(arr[i]<=target){
                    pick=dp[i-1][target-arr[i]];
                }
                dp[i][target]=pick || notpick;
            }
        }
        return dp[n-1][sum];
    }