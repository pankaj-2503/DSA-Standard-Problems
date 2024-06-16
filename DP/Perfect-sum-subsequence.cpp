// N = 6
// arr = [5, 2, 3, 10, 6, 8]
// sum = 10
// Output: 
// 3
// Explanation: 
// {5, 2, 3}, {2, 8}, {10} are possible subsets.


class Solution{
   // recursive approach - Time complexity - O(2^n) , space complexity - O(n) recursion stack
   // memoization approach - Time complexity - o(N*sum) , space complexity - O(N*sum)-> for 2D vector
   // tabulation approach - Time complexity - O(N*sum) , space complexity - O(N*sum) -> for 2D vector
   
   int mod=(int)(1e9+7);
	int solve(int index,int arr[],int target){
	    if(index<0){
	        if(target==0) return 1;
	        else return 0;
	    }
	    int pick=0;
	    if(target>=arr[index]) pick=(solve(index-1,arr,target-arr[index]))%mod;
	    int notpick=(solve(index-1,arr,target))%mod;
	    return (pick+notpick)%mod;
	}

    
    int solveMem(int ind, int sum, int arr[], vector<vector<int>> &dp){
        if(ind==0)
        {
            if(sum==0 && arr[0]==0) return 2;
            if(arr[0]==sum || sum==0) return 1;
            return 0;
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int notPick = solveMem(ind-1,sum,arr,dp);
        int pick = 0;
        if(sum >= arr[ind]){
            pick = solveMem(ind-1,sum-arr[ind],arr,dp);
        }
        
        return dp[ind][sum] = (pick + notPick)%mod;
    }
    


    
	int perfectSum(int arr[], int n, int sum)
	{
        // recursion
        int index=n-1;
        int ans=solve(index,arr,sum);
        return ans;
        
        // memoization
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans=solveMem(n-1,sum,arr,dp);
        return ans;
        
        // tabulation
           
             vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
                
            for (int i = 0; i <= n; i++) {
                dp[i][0] = 1;  // There's one way to make sum 0 (by choosing no elements)
            }
    
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= sum; j++) {
                    int pick=0;
                    if (arr[i-1] <= j) {
                        // pick + not pick
                        pick = (dp[i-1][j - arr[i-1]]) % mod;
                    } 
                    int notpick = dp[i-1][j];
                    
                    dp[i][j]=(pick+notpick)%mod;
                }
            }
        
            return dp[n][sum];
            
	}
};



/// another approach using 0 based indexing instead of last index


#include <vector>
#include <cstring>
using namespace std;

int mod = (int)(1e9 + 7);
int solve(int index,int cursum,int sum,int arr[],int n){
	    if(index==n){
	        if(cursum==sum) return 1;
	        else return 0;
	    }
	    
	    //pick
	    int pick=solve(index+1,cursum+arr[index],sum,arr,n);
	    // notpick
	    int notpick=solve(index+1,cursum,sum,arr,n);
	    return (pick+notpick)%mod;
	}

int solveMem(int index, int cursum, int sum, int arr[], int n, vector<vector<int>>& dp) {
    // Base case: when we have considered all elements
    if (index == n) {
        return cursum == sum ? 1 : 0;
    }

    // Check if the subproblem is already solved
    if (dp[index][cursum] != -1) {
        return dp[index][cursum];
    }

    // Exclude the current element
    int notpick = solveMem(index + 1, cursum, sum, arr, n, dp);

    // Include the current element if it doesn't exceed the sum
    int pick = 0;
    if (cursum + arr[index] <= sum) {
        pick = solveMem(index + 1, cursum + arr[index], sum, arr, n, dp);
    }

    // Store the result and return it
    return dp[index][cursum] = (pick + notpick) % mod;
}

int perfectSum(int arr[], int n, int sum) {
    // Create a dp array with dimensions (n+1) x (sum+1) and initialize with -1
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    // Start the memoized recursion from index 0 and initial sum 0
    return solveMem(0, 0, sum, arr, n, dp);
}

