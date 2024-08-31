class Solution {
public:
// TC: O(N)
    int maxDepth(string s) {
        int mx=0,n=s.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                mx=max(mx,cnt);
            }
            else if(s[i]==')') cnt--;

        }
        return mx;
    }
};