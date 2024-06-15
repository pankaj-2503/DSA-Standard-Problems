class Solution {
public:
// Time complexity - O(2^n) , space complexity - O(N)
    void solve(int open,int close,int n,vector<string>&ans,string s){
         if(open==close && open==n){
            ans.push_back(s);return;
         }
         if(open<n){
            solve(open+1,close,n,ans,s+"(");
         }
         // since open should be more then close or equal
         if(close<open){
            solve(open,close+1,n,ans,s+")");
         }

    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string>ans;string s="";
        solve(open,close,n,ans,s);
        return ans;
    }
};