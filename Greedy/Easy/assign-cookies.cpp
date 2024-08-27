class Solution {
public:
// TC:-> O(N+m) , SC-> O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]) i++;     
            j++;
        }
        return i;
    }
};