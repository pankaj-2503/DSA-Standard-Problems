class Solution {
public:
// TC: O(N), SC:O(N)
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string>ans;
        while(ss>>word){
            ans.push_back(word);
        }
        reverse(ans.begin(),ans.end());
        string res="";
        for(auto i:ans) res+=i+' ';
        res.pop_back();
        return res;
    }
};