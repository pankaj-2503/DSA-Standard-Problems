class Solution{
    public:
    // TC : O(Nlogn) , SC: O(N)
    int longestKSubstr(string s, int k) {
    // your code here
     int n=s.size();
     int left=0,right=0,mx=-1;
     unordered_map<char,int>m;
     while(right<n){
         m[s[right]]++;
         
         if(m.size()>k){
            if(m[s[left]]==1) m.erase(s[left]);
            else m[s[left]]--;
            left++;
         }
         
         if(m.size()==k){
             mx=max(mx,right-left+1);
             
         }
         right++;
         
         
     }
     return mx;
    }
};