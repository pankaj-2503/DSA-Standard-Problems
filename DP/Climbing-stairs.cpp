class Solution {
public:
// recursion 
// Time complexity- O(2^n), space complexity - O(1)
   int solve(int n){
      if(n==0 || n==1) return 1;
      return solve(n-1)+solve(n-2);
   }
    int climbStairs(int n) {
      return solve(n);
    }
};

// Memoization
// Time complexity- O(n), space complexity - O(n)
class Solution {
public:
   int solveMem(vector<int>&dp,int n){
      if(n==0 || n==1) return 1;
      if(dp[n]!=-1) return dp[n];
      return dp[n]=solveMem(dp,n-1)+solveMem(dp,n-2);
   }
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       return solveMem(dp,n);
    }
};

// Tabulation
// Time complexit - O(n), space complexity - O(n)
class Solution {
public:

    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       dp[0]=1;
       dp[1]=1;
       for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
       }
       return dp[n];
    }
};


// Space optimization
// Time complexity - O(N), space complexity - O(1)

class Solution {
public:

    int climbStairs(int n) {

       int prev2=1;
       int prev1=1;
       for(int i=2;i<=n;i++){
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
       }
       return prev1;
    }
};