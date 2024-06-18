// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Phone letter are mapped like 1-abc,2-def,3-ghi,4-jkl,5-mno,6-pqrs,7-tuv,8-wxyz
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){return {};}
        vector<string>m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        ans.push_back("");
        for(auto i:digits){
            vector<string>temp;
            for(auto j:m[i-'0']){
                for(auto k:ans){
                    temp.push_back(k+j);
                }
            }
            ans.clear();
            ans=temp;
        }
        return ans;
    }
};