// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"


class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        string ans="";
        stack<int>num;
        stack<string>st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int count=0;
                while(i<n && isdigit(s[i])){
                    count=count*10+(s[i]-'0');
                    i++;
                }
                i--;
                num.push(count);
            }
            else if(s[i]=='['){
                st.push(ans);
                ans="";
            }
            else if(s[i]==']'){
                int repeat=num.top();num.pop();
                string temp=st.top();st.pop();
                for(int j=0;j<repeat;j++) temp+=ans;
                ans=temp;
            }
            else ans+=s[i];
        }
        return ans;
    }
};