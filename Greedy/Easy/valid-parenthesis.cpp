class Solution {
public:
// TC: O(N), SC:O(1)
    bool checkValidString(string s) {
        int cur=0,total=0;
        for(auto i:s){
            if(i=='('){cur++;total++;}
            else if(i==')'){cur--;total--;}
            else{cur--;total++;}
            if(cur<0) cur=0;
            if(total<0) return false;
        }
        if(cur==0) return true;
        return false;
    }
};