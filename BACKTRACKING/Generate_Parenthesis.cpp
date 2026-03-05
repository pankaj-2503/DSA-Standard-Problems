class Solution {
public:

    // TC -> O(n*C(n)) where C(n) is catalan number given by C(n)-> (1/(n+1))(2n /n)
    void dfs(int open,int close,string s,int n,vector<string>&ans){
        if(open==close && open+close==2*n){
            ans.push_back(s);return;
        }
        if(open<n){
            dfs(open+1,close,s+"(",n,ans);
        }
        if(close<open){
            dfs(open,close+1,s+")",n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        // cnt of open,close bracket with string , n and vector<string>ans
        dfs(0,0,"",n,ans);
        return ans;
    }
};

For n=1
()
n = 2
(())
()()

n = 3
((()))
(()())
(())()
()(())
()()()

Every valid parentheses string must:

(  something  )  something -> (  A  )  B


Suppose:

A uses j pairs

B uses n - j - 1 pairs
(because 1 pair is used by outer parentheses)

So:

dp[n] = for j in 0 to n-1:
          "(" + dp[j] + ")" + dp[n-j-1]

This is catalan recurrence -> C(N) = (j=0-n-1)∑C(j)*C(n-j-1)


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>>dp(n+1);
        dp[0]={""};
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                for(string left:dp[j]){
                    for(string right:dp[i-j-1]){
                        dp[i].push_back("("+left+")"+right);
                    }
                }
            }
        }
        return dp[n];
    }
};

