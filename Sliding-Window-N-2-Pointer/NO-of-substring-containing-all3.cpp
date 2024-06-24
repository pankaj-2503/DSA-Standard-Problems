// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

class Solution {
public:
// Time complexity - O(N), space complexity - O(1)
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0,mx=0;
        unordered_map<char,int>m;
        while(r<n){
            m[s[r]]=m[s[r]]+1;
            while(m['a']>0 && m['b']>0 && m['c']>0){
                mx+=(n-r);  // since after this would definitely be substring containing a,b,c
                m[s[l]]--;
                l++;
            }
            r++;
        }
        return mx;
    }
};