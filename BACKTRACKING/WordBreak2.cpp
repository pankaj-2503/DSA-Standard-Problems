class Solution {
public:
//Time complexity - O(2^N) , Space complexity - O(2^N)
    unordered_map<string,vector<string>>dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //edge case where aaaaaa all are same we would be calculating again and again so we need to cache it beforehand
        if(dp.find(s)!=dp.end()) return dp[s];


        vector<string>result;
        for(auto i:wordDict){

            // if worddict[i] string is equal to first sub_string in s
            if(i==s.substr(0,i.size())){

                //base case: if s size is equal to worddict[i] then push drectly to resulut
                if(i.size()==s.size()){
                    result.push_back(i);
                }else{
                    //recursive calls
                    vector<string>temp=wordBreak(s.substr(i.size()),wordDict);
                    for(auto j:temp){
                        result.push_back(i+" "+j);
                    }
                }
            }
        }

        dp[s]=result;

        return result;
    }
};

// Backtracking
class Solution {
public:
   // Time complexity - O(2^N) since we can take particular index or nottake
   // Space complexity - O(N*2^N)
    void solve(string &s,int index,string &curr,vector<string>&ans,unordered_set<string>&wordSet){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=index+1;i<=s.size();i++){
            string word=s.substr(index,i-index);
            if(wordSet.find(word)!=wordSet.end()){
                string prev=curr.empty()?word:(curr+" "+word);
                solve(s,i,prev,ans,wordSet);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        vector<string>ans;
        string curr;
        int index=0;
        solve(s,index,curr,ans,wordSet);
        return ans;
    }
};