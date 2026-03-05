class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.size()!=goal.size()) return false;
       s+=s;
       return s.contains(goal);
    }
};

// tC -> O(n*n) , sC -> O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
      if(s.size()!=goal.size()) return false;
      for(int i=0;i<s.size();i++){
        string p=s.substr(i)+s.substr(0,i);
        if(p==goal) return true;
      }
      return false;

    }
};