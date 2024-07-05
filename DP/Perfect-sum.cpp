class Solution{
  public:
  // Recursion -> Time complexity - O(2^N),space complexity - O(N)
  int mod=1e9+7;
	int solve(int arr[],int index,int target){
	    if(target==0) return 1;
	    if(index==0){
	        if(arr[index]==target) return 1;
	        return 0;
	    }
	    int notpick=solve(arr,index-1,target);
	    int pick=0;
	    if(arr[index]<=target)
	     pick=solve(arr,index-1,target-arr[index]);
	    return (pick+notpick)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        sort(arr,arr+n,greater<int>()); // this is done because if arr is sorted and 0 appears before target then it would directly return 1
        return solve(arr,n-1,sum);
	}
	  
};

// Memoisation -> time complexity - O(N*sum), space complexity-O(N*sum)+O(N)
int mod=1e9+7;
	int solve(int arr[],int index,int target,vector<vector<int>>&dp){
	    if(target==0){
	        return 1;
	    }
	    if(index==0) {
            return (arr[0]==target);
	    }
	    
	    if(dp[index][target]!=-1) return dp[index][target];
	    
	    int notpick=solve(arr,index-1,target,dp)%mod;
	    int pick=0;
	    if(arr[index]<=target)
	     pick=solve(arr,index-1,target-arr[index],dp)%mod;
	    return dp[index][target]=(pick+notpick)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        sort(arr,arr+n,greater<int>());
        return solve(arr,n-1,sum,dp);
	}

// Tabulation -> time complexity - O(N*sum), space complexity - O(n*sum)
	int perfectSum(int arr[], int n, int sum)
	{
        
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        sort(arr,arr+n,greater<int>());
        
        // base case if target is 0
        if(sum==0){
            for(int i=0;i<n;i++) dp[i][0]=1;
        }
       
        if(arr[0]<=sum) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                int notpick=dp[i-1][target];
                int pick=0;
                if(arr[i]<=target){
                    pick=dp[i-1][target-arr[i]];
                }
                dp[i][target]=(pick+notpick)%mod;
            }
        }
        return dp[n-1][sum];
        
	}