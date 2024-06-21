class Solution {
public:

// Time complexity - O(N*logN)
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int right=0,left=0,maxlen=0;
        set<char>st;
        while(right<s.size()){
           auto it=st.find(s[right]);
           if(it==st.end()){
               maxlen=max(maxlen,right-left+1);
               st.insert(s[right]);right++;
           }
           else{
               st.erase(s[left]);left++;
           }
        }
        return maxlen;
    }
};