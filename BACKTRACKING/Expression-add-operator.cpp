
class Solution {
public:
    // Time complexit - O(3^N) , space complexity - O(n^3)
     vector<string> ans;
     void helper(string s, int target,int index, const string& path, long eval, long residual) {
        // bc
        if(index==s.length()){
            if(eval==target){
                ans.push_back(path);
                return;
            }
        } 
        string currStr;
        long num=0;
        // backtracking loop
        for(int j=index;j<s.length();j++){
            // handle 0
            if(j>index && s[index]=='0') return; //skip leading 0's
            currStr+= s[j]; 
            num= num*10 + s[j]- '0';
            if(index==0){
                helper(s,target, j+1,path+ currStr,num, num);
            }
            else{
                helper(s,target,j+1,path + "+" + currStr, eval + num, num);
                helper(s,target,j+1,path + "-" + currStr, eval - num, -num);
                helper(s,target,j+1,path + "*" + currStr, eval -residual + residual*num , residual*num);


            }
        }
        
        
    }

    vector<string> addOperators(string s, int target) {
        helper(s,target, 0, "", 0, 0);
        return ans;
    }
   
};