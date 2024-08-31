class Solution {
public:
// TC: O(N^2)
        string longestPalindrome(string s) {
            int n=s.size();
            auto check=[&](string t,int left, int right){
            while(left>=0 && right<n && t[left]==t[right]){
                left--;right++;
            }
            return right-left-1;
            };

            int ans=0,start=0;
            for(int i=0;i<n;i++){
                int len1=check(s,i,i);
                int len2=check(s,i,i+1);
                int total=max(len1,len2);
                
                if(total>ans) ans=total,start=i-(total-1)/2;


            }
        return s.substr(start,ans);
        }
    
  
};