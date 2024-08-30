class Solution {
public:
// TC: O(N)
    string removeOuterParentheses(string s) {
        string ans="";
       
        int n=s.size(),cnt=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
               if(cnt>0){
                ans+=s[i];
               }
               cnt++;
            }
            else if(s[i]==')' && cnt>0){
               --cnt;
               if(cnt>0) ans+=s[i]; 

            }
            
        }
        return ans;
    }
};