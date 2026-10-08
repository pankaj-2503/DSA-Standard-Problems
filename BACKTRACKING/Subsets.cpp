class Solution {
public:
    // TC -> O(2^n*n), SC -> O(N)
    void solve(int idx,vector<int>&nums,vector<int>&res,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(res);
            return;
        }
        //include current element
        res.push_back(nums[idx]);
        solve(idx+1,nums,res,ans);

        res.pop_back(); //backtrack

        // exclude the current element
        solve(idx+1,nums,res,ans);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(0,nums,res,ans);
        return ans;
    }
};