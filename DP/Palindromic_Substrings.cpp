class Solution {
public:
    // TC : O(N^3)
    bool check(string &s,int i,int j){
        bool ok=false;
        while(s[i]==s[j]){
            i++;j--;
            if(i>j){
                ok=true;break;
            }
        }
        return ok;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)) cnt++;
            }
        }
        return cnt;
    }
};

// Recursive Approach , TC -> O(N^3), SC -> O(N)
class Solution {
public:

    bool ispalind(string &s,int i,int j){
        if(i>j) return true;
        if(s[i]!=s[j]) return false;

        return ispalind(s,i+1,j-1);

    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(ispalind(s,i,j)) cnt++;
            }
        }
        return cnt;
    }
};

// Memoisation -> TC: O(N^2), SC:O(N^2)
class Solution {
public:
    vector<vector<int>>dp;
    int n;
    bool ispalind(string &s,int i,int j){
        if(i>j) return true;
        if(s[i]!=s[j]) return false;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=ispalind(s,i+1,j-1);

    }

    int countSubstrings(string s) {
        n=s.size();
        int cnt=0;
        dp.assign(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(ispalind(s,i,j)) cnt++;
            }
        }
        return cnt;
    }
};

// Tabulation -> TC:O(n^2), SC:O(N^2)

class Solution {
public:

    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
         // dp[i][j] represent , s[i..j] is palindrome or not
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        // 1 length substring is palindrom
        for(int i=0;i<n;i++){
            dp[i][i]=true;cnt++;
        }

        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len==2 || dp[i+1][j-1]){
                        dp[i][j]=true;cnt++;
                    }
                }
            }
        }


        return cnt;
    }
};

// Expanding around center -> TC:O(n^2), SC:O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            // odd length palindrome , expanding around centre
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
               l--;r++;
               cnt++;
            }
            // even length palindrome , expanding around centre
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
                cnt++;
            }
        }
        return cnt;
    }
};