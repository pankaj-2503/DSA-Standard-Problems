class Solution {
public:
    string removeKdigits(string num, int k) {
        // we need to use monotonous stack
        stack<int>s;
        for(auto i:num){
            while(!s.empty() && k>0 && s.top()>i){
                s.pop();k--;
            }
            s.push(i);
        }
        string ans;
        while(k>0 && !s.empty()){
            s.pop();k--;
        }
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        auto pos=ans.find_first_not_of('0');
        ans=(pos==string::npos)?"0":ans.substr(pos);
        return ans;
    }
};