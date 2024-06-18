class Solution {
public:
    // bool solve(string s,unordered_set<string>&set){
    //     // Time complexity - O(2^N), space complexity- O(N)
    //     if(s.size()==0) return true;
    //     for(int i=0;i<s.size();i++){
    //         if(set.count(s.substr(0,i+1)) && solve(s.substr(i+1),set)) return true;
    //     }
    //     return false;
    // }

    // bool solve(string s, unordered_set<string> &set, int start){
        //Time complexity - O(2^N),space complexity-O(N)
    //     if(start == s.size()){
    //         return true;
    //     }
    //     for(int i=start; i<s.size(); i++){
    //         if(set.count(s.substr(start, i+1-start)) && solve(s, set, i+1)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    bool solve(string s, unordered_set<string> &set, int start,vector<int>&memo){
        // Time complexity - O(N^3),space complexity-O(N+M) , where M is set storage length and N is recursion call stack
        if(start == s.size()){
            return true;
        }
        if(memo[start]!=-1) return memo[start];
        for(int i=start; i<s.size(); i++){
            if(set.count(s.substr(start, i+1-start)) && solve(s, set, i+1,memo)){
                memo[start]=true;
                return true;
            }
        }
        return memo[start]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>memo(s.size(),-1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return solve(s, set, 0,memo);
    }
};