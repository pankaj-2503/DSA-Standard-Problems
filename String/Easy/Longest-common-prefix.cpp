class Solution {
public:
// TC: O(N+log(M))
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs[0].size();
        int m=strs.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(strs[0][i]==strs[m-1][i]) ans+=strs[0][i];
            else break;
        }
        return ans;
    }
};