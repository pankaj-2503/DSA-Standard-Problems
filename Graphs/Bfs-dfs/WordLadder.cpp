class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // we would use bfs traversal to change each character and mark is visited in set
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string p=q.front().first;
            int step=q.front().second;
            q.pop();

            if(p==endWord) return step;

            for(int i=0;i<p.size();i++){
                char original=p[i];
                for(char ch='a';ch<='z';ch++){
                    p[i]=ch;
                    // if exist in set 
                    if(s.find(p)!=s.end()){
                        q.push({p,step+1});
                        s.erase(p);
                    }
                }
                p[i]=original;
            }
        }
        return 0;
        // TC : O(N*wordlength*26*log(N))
    }
};