class Solution {
public:
   // Time Complexity: O( (2^n) *k*(n/2) , space complexity ~ O(k*x), k is avg. length of palindrom
   // and x is such palindrom's
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
        if (s[start++] != s[end--])
            return false;
        }
        return true;
    }


    void partitionHelper(int index, string s, vector < string > & path,
            vector < vector < string > > & res) {
            if (index == s.size()) {
            res.push_back(path);
            return;
            }
            for (int i = index; i < s.size(); ++i) {
                if (isPalindrome(s, index, i)) {
                    path.push_back(s.substr(index, i - index + 1));
                    partitionHelper(i + 1, s, path, res);
                    path.pop_back();
                }
            }
    }
    vector<vector<string>> partition(string s) {
        vector < vector < string > > res;
        vector < string > path;
        partitionHelper(0, s, path, res);
        return res;
    }
};