class Solution {
public:
// tC: O(N) , same SC
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='[') st.push(i);
            else{
                if(st.empty()) return false;
                else{
                    char top=st.top();
                    if((top=='(' && i==')') || (top=='{' && i=='}') || (top=='[' && i==']'))
                    st.pop();
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};