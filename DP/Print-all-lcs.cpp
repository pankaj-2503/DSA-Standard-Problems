 set<string> st;
    
    void dfs(vector< vector<int>>& dp, string s1, string s2, int i, int j, string word, int maxLen) {
        
        if (word.length() == maxLen) {
            reverse(word.begin(), word.end());
            st.insert(word);
            return;
        }
        
        if (i == 0 || j == 0) {
            return;
        }
        
        
        
        if (s1[i-1] == s2[j-1]) {
            dfs(dp, s1, s2, i-1, j-1, word+s1[i-1], maxLen);
        } else {
            
            if (dp[i-1][j] >= dp[i][j-1]) {
                dfs(dp, s1, s2, i-1, j, word, maxLen);
            } 
            if (dp[i-1][j] <= dp[i][j-1])  {
                dfs(dp, s1, s2, i, j-1, word, maxLen);
            } 
        }
    }
    
	
	vector<string> all_longest_common_subsequences(string s, string t) {
	    
	    int n = s.length();
	    int m = t.length();
	    
	    vector< vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
	    
	    for (int i = 1; i <= s.length(); ++i) {
	        for (int j = 1; j <= t.length(); ++j) {
	            
	            if (s[i-1] == t[j-1]) {
	                dp[i][j] = 1 + dp[i-1][j-1];
	            } else {
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    
	    int maxLen = dp[n][m];
	    
	    vector<string> ans;
	    
	    dfs(dp, s, t, n, m, "", maxLen);
	    
	    for (auto it : st) {
	        ans.push_back(it);
	    }
	  
	    return ans;
	    
	}