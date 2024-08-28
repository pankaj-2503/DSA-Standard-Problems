class Solution {
public:
// TC: O(N*L) , SC: O(N*L)
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);

        vector<vector<string>>v;
        while(!q.empty()){
            string p=q.front().first;
            int step=q.front().second;
            q.pop();

            if(p==endWord) return v;
            vector<string>temp;
            for(int i=0;i<p.size();i++){
                char original=p[i];
                for(char ch='a';ch<='z';ch++){
                    p[i]=ch;
                    // if exist in set 
                    if(s.find(p)!=s.end()){
                        temp.push_back({p});
                        s.erase(p);
                    }
                }
                p[i]=original;
            }
            // v.push_back(temp);
        }
        return v;
    }
};