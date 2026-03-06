class Solution {
public:
    // TC -> O(n),SC -> O(5)
    int maxVowels(string s, int k) {
        string check="aeiouAEIOU";
        int mx=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if(check.find(s[i])!=string::npos) cnt++;
            if(i>=k && check.find(s[i-k])!=string::npos ) cnt--;
            mx=max(mx,cnt);
        }
        return mx;
    }
};


// Prefix sum

class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> prefix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + isVowel(s[i]);
        }

        int ans = 0;

        for(int i=0;i<=n-k;i++){
            ans = max(ans, prefix[i+k] - prefix[i]);
        }

        return ans;
    }
};