class Solution {
public:
// TC: O(N+M) , sc:O(N+M)
    string shortestPalindrome(string s) {
        if(s=="") return s;
        string rev=s;
        reverse(rev.begin(),rev.end());
        string str=s+"@"+rev;
        int n=str.size();
        vector<int>lps(n,0) ;// to keep storing longest prefix string 
        int i=0;
        for(int j=1;j<n;){
            if(str[i]==str[j]){
                lps[j]=i+1;
                i++;j++;
            }else{
                if(i!=0){ // fall back to prev lps
                    i=lps[i-1];
                }else{
                    lps[j]=0;j++; // no match ,move forward
                }
            }
        }
        string temp=s.substr(i);
        reverse(temp.begin(),temp.end());
        return temp+s;

    }
};