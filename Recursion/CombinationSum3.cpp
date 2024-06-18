class Solution {
public:
   // Time complexity - O(2^9) , space complexity - O(k+n)
    void solve(int index,vector<vector<int>>&ans,vector<int>&output,int k,int target){
        if(target==0 && output.size()==k){
            ans.push_back(output);
            return;
        }
        if(output.size()>k || target<0) return;
        for(int i=index;i<=9;i++){
            output.push_back(i);
            solve(i+1,ans,output,k,target-i);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>output;
        
        
        solve(1,ans,output,k,n);
        return ans;
    }
};
auto init=[](){
    ios::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
};