class Solution {
public:
// Permutation problem leetcode
// tc -> O(n!*n) , sc -> O(n)
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&res,vector<bool>&freq){
        // base case
        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=true;
                res.push_back(nums[i]);
                solve(nums,ans,res,freq);

                //backtrack
                res.pop_back();
                freq[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        vector<bool>freq(nums.size(),false); // which element hasn't been used
        solve(nums,ans,res,freq);
        return ans;
    }
};



// Permutation 2 -> leetcode



class Solution {
public:
    // TC -> O(N!*N) , SC -> O(N)
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&res,vector<bool>&visited){
        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]==true) continue;

            visited[i]=true;
            res.push_back(nums[i]);
            solve(nums,ans,res,visited);

            //backtrack
            res.pop_back();
            visited[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        vector<bool>visited(nums.size(),false);

        sort(nums.begin(),nums.end());
        solve(nums,ans,res,visited);
        return ans;
    }
};