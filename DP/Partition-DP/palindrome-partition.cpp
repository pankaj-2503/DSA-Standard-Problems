// tC -> O(N*(2^N)) , sc -> same as tc
class Solution {
public:

vector<vector<string>>result;
vector<string>path;
bool isPalindrome(const string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    void solve(string &s,int index){
        if(index==s.size()){
            result.push_back(path);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                // choose
                path.push_back(s.substr(index,i-index+1));
                solve(s,i+1); // explore
                path.pop_back(); // backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        solve(s,0);
        return result;

    }
};