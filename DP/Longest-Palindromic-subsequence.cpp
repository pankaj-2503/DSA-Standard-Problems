class Solution {
public:
   // Note : longest palindrom subsequence is nothing but longest common subsequence 
   // of string s and reverse of s

//    Time Complexity: O(N*N),same space complexity
    int lcs(string p,string q){
        int n=p.size(),m=q.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==q[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        return lcs(s,t);
    }
};


// Space optimisation -> space complexity - O(2*n)
class Solution {
public:
   // Note : longest palindrom subsequence is nothing but longest common subsequence 
   // of string s and reverse of s
    int lcs(string p,string q){
        int n=p.size(),m=q.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (p[ind1 - 1] == q[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        // Update the prev array with the current values
        prev = cur;
    }

    // The value at prev[m] contains the length of the LCS
         return prev[m];
    }

    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        return lcs(s,t);
    }
};