class Solution {
public:
// Time Complexity: O(N*M) , same space complexity
    string shortestCommonSupersequence(string s1, string s2) {
        if(s1==s2) return s1;
        int n=s1.size(),m=s2.size();
        vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        int len = dp[n][m];
        int i = n;
        int j = m;

        int index = len - 1;
        string ans = "";
        
        // to find string of longest common subsequence
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i-1];
            index--;
            i--;
            j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i-1];
                i--;
            } else {
                ans += s2[j-1];
                j--;
            }
        }
        
        //Adding Remaing Characters - Only one of the below two while loops will run 
        
        while(i>0){
            ans += s1[i-1];
            i--;
        }
        while(j>0){
            ans += s2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};