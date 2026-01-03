class Solution {
public:

    // Approach 1: Time complexity - O(N^3) , Space Complexity - O(1)
    bool check(string &s,int i,int j){
        bool ok=true;
        while(i<j){
           if(s[i]!=s[j]){
            ok=false;break;
           }
           i++;j--;

        }
        return ok?true:false;



    }
    string longestPalindrome(string s) {
        int n=s.size();
        int mx=0;
        string ans;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j) && j-i+1>mx){

                    mx=max(mx,j-i+1);
                    ans=s.substr(i,j-i+1);
                }

            }
        }
        return ans;
    }


};


class Solution {
    public:

    // Approach 2: Expanding around center for palindrome search , TC :O(N^2) , SC : O(1)
    string longestPalindrome(string s) {
        int n=s.size();
        int ind=0,mxlen=0;
        for(int i=0;i<n;i++){
            // odd len palindrome
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>mxlen){
                    mxlen=r-l+1;
                    ind=l;
                }
                l--;r++;

            }
            // even len palindrome
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>mxlen){
                    mxlen=r-l+1;
                    ind=l;
                }
                l--;r++;
            }
        }
        return s.substr(ind,mxlen);
    }
};

// Approach 3: Using DP  , TC : O(N^2), SC:O(N^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        // dp[i][j] represent whether string s[i,j] is palindrome or not
        int start=0,mxlen=1;
        vector<vector<int>>dp(n,vector<int>(n,false));
        // All substring of len 1 are palindrome
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        // Substrings of len 2 base case
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                mxlen=2;
            }
        }
        // building dp array with checking each len palindrome possible or not
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(len>mxlen){
                        mxlen=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,mxlen);

    }
};


// Manacher Algorithm , TC - O(N), SC: O(N)

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        // Step 1: Transform string
        string t = "#"; // here we are converting it to odd length string
        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();
        vector<int> p(n, 0);
        // Remember the original p array after calculation would have value -1 would be the actual mxlength palindrome at index i

        int center = 0, right = 0;

        // Step 2: Main loop
        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            // Use previously computed palindrome
            if (i < right) {
                p[i] = min(right - i, p[mirror]);
            }

            // Expand around i
            int left = i - (p[i] + 1);
            int r = i + (p[i] + 1);

            while (left >= 0 && r < n && t[left] == t[r]) {
                p[i]++;
                left--;
                r++;
            }

            // Update center and right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        // Step 3: Find maximum palindrome
        int maxLen = 0;
        int centerIndex = 0;

        for (int i = 0; i < n; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        // Step 4: Extract answer
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};


// CP Style use of manacher algorith

struct manacher{
    vector<int>p;
    void run_manacher(string s){
        cout<<s<<endl;
        int n=s.length();
        p.assign(n,1);
        int l=1,r=1;
        for(int i=1;i<n;i++){
            p[i]=max(0,min(r-i,p[l+r-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]) p[i]++;
            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }
        for(auto v:p) cout<<v<<" ";
        cout<<endl;
    }
    void build(string s){
        string t;
        for(auto v:s){
            t+=string("#")+v;
        }
        run_manacher(t+"#");
    }
    int getLongest(int cen,bool odd){
        int pos=2*cen+1+(!odd);
        return p[pos]-1;
    }
    bool checkPalin(int l,int r){
        if((r-l+1)<=getLongest((l+r)/2,l%2==r%2)) return 1;
        else return 0;
    }
}m;

void solve(){
    string s="babbabbabc";
    m.build(s);
}
