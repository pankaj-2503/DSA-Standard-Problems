class Solution {
public:
int n;
int dp[2002];
// Memoisation approach -> TC : O(N*N) , SC: O(N)+O(N)
    bool isPalindrome(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
    int solve(string& s, int idx)
    {
        if(idx >= n) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int minSteps = INT_MAX;
        for(int k=idx; k<n; k++)
        {
            if(isPalindrome(s, idx, k))
            {
                int steps = 1 + solve(s, k+1);
                minSteps = min(minSteps, steps);
            }
        }
        return dp[idx]=minSteps;
    }
    int minCut(string s) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s, 0) - 1; // since for partitioning we need length -1 cuts
    }
};

// Tabulation approach -> TC : O(N*N) , SC: O(N)


class Solution{
private:
    bool isPalindrome(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--)
        {
            int minSteps = INT_MAX;
            for(int k=i; k<n; k++)
            {
                if(isPalindrome(s, i, k))
                {
                    int steps = 1 + dp[k+1];
                    minSteps = min(minSteps, steps);
                }
            }
            dp[i] = minSteps;
        }
        return dp[0] - 1;
    }
};


// Here is striver solution: 
// recursion + memoisation
// TC: O(N^2) , SC: O(N)+O(N)

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to find the minimum number of partitions to make palindromes.
int minPartitions(int i, int n, string &str, vector<int> &dp) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

// Main function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    return minPartitions(0, n, str, dp) - 1;
}