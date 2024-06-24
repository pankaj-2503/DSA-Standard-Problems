class Solution {
public:
// Recursion
// Time complexity - O(2*(2^N)) , space complexity- O(2N)
    int solve(vector<int>&nums,int ind){
       
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        int pick=nums[ind]+solve(nums,ind-2);
        int notpick=0+solve(nums,ind-1);
        return max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>v1(nums.begin(),nums.end()-1); // excluding last house
        vector<int>v2(nums.begin()+1,nums.end());// excluding first house
        int p=solve(v1,n-2);
        int q=solve(v2,n-2);
        return max(p,q);
    }
};

// Memoization
// Time complexity - O(2N) , space complexity - O(2N)
class Solution {
public:
    int solve(vector<int>&nums,int ind,vector<int>&dp){
       
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+solve(nums,ind-2,dp);
        int notpick=0+solve(nums,ind-1,dp);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        vector<int>dp(n,-1);
        vector<int>v1(nums.begin(),nums.end()-1); // excluding last house
        vector<int>v2(nums.begin()+1,nums.end());// excluding first house
        int p=solve(v1,n-2,dp);
        // here dp array would have stored result so we need to make it default -1
        for(int i=0;i<n;i++) dp[i]=-1;
        int q=solve(v2,n-2,dp);
        return max(p,q);
    }
};

// Tabulation
class Solution {
public:
    int solve(vector<int>&arr,vector<int>&dp){
        dp[0]=arr[0];
        int n=arr.size();
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1) pick+=dp[i-2];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,0);
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        int p=solve(v1,dp);
        int q=solve(v2,dp);
        return max(p,q);
    }
};


// space optimised
// Time complexity - O(N) ,space complexity - O(1)
class Solution {
public:
    int solve(vector<int>&arr){
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1) pick+=prev2;
            int notpick=prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;

    }
    int rob(vector<int>& nums) {
        vector<int>v1,v2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) v1.push_back(nums[i]);
            if(i!=n-1) v2.push_back(nums[i]);
        }

        int p=solve(v1);
        int q=solve(v2);
        return max(p,q);
    }
};