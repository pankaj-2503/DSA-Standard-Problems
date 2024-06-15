
// recursive
class Solution {
public:
   
   // Time complexity - O(2^N) , Space complexity - O(N)

    void solve(vector<vector<int>>&ans,vector<int>output,int n,int idx,vector<int>nums){
        if(idx>=n) {ans.push_back(output);return;}

        solve(ans,output,n,idx+1,nums); //exclude
        int element=nums[idx];
        output.push_back(element);
        solve(ans,output,n,idx+1,nums); // include
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>output;
       int n=nums.size();
       int idx=0;
       solve(ans,output,n,idx,nums);
       return ans;
    }
};

// using bit manipulation
class Solution {
public:
    // Time complexity - (2^n)*n; space complexity - O(2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       int n=nums.size();
       for(int i=0;i<(1<<n);i++){
       vector<int>temp;
          for(int bit=0;bit<n;bit++){
            //if bit is set then push into temp
            if(i&(1<<bit)) temp.push_back(nums[bit]);
          }
          ans.push_back(temp);
       }
       return ans;
    }
};