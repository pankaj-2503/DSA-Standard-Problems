class Solution {
public:
// TC: O(n^2)
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int mx=INT_MIN;
                int mn=INT_MAX;
                for(auto it:m){
                    mx=max(mx,it.second);
                    mn=min(mn,it.second);
                }
                sum+=mx-mn;
            }
            m.clear();
        }
        return sum;
    }
};