class Solution {
public:
    // TC -> O(2^(N-1) * N) , SC -> O(2^(N-1) *N) + O(N) auxilary space
    vector<vector<string>>ans;
    vector<string>path;
    bool palindromeCheck(string &s,int i,int j){
        while(i<=j && s[i]==s[j]){
            i++;j--;
        }
        return i>j;
    }

    void solve(string &s,int idx){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(palindromeCheck(s,idx,i)){
                string temp=s.substr(idx,i-idx+1);
                path.push_back(temp);

                solve(s,i+1);

                path.pop_back();
            }

        }
    }



    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};


// optimising through dp

class Solution {
public:
    // TC -> O(2^(N-1) * N) , SC -> O(2^(N-1) *N ) + O(N^2) auxilary space .We can use a 2D boolean DP table or memoization array dp[i][j] that pre-calculates whether the substring from index i to j is a palindrome in $O(1)$ time


    vector<vector<string>>ans;
    vector<string>path;
    vector<vector<bool>>dp;
    bool palindromeCheck(string &s,int i,int j){
        while(i<=j && s[i]==s[j]){
            i++;j--;
        }
        return i>j;
    }

    void solve(string &s,int idx){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(s[idx]==s[i] && (i-idx<=2 || dp[idx+1][i-1] )){
                dp[idx][i]=true;
                string temp=s.substr(idx,i-idx+1);
                path.push_back(temp);

                solve(s,i+1);

                path.pop_back();
            }

        }
    }



    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp.assign(n,vector<bool>(n,false));
        solve(s,0);

        return ans;
    }
};