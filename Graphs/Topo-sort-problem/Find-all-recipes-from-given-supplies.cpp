class Solution {
    public:
        // TC : O(n+e), SC : O(n+e)
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n=recipes.size();
            unordered_set<string> supp(supplies.begin(), supplies.end());
            vector<int> deg(n, 0);
            unordered_map<string, vector<int>> adj; // ingredients that depends on recipe

            for (int i = 0; i < n; i++) {
                for (const string& s : ingredients[i]) {
                    if (!supp.count(s)) {
                        adj[s].push_back(i);
                        deg[i]++;
                    }
                }
            }

            queue<int> q;
            for (int i = 0; i < n; i++)
                if (deg[i] == 0) q.push(i);

            vector<string> ans;
            while (!q.empty()) {
                const int i = q.front();
                q.pop();
                auto s=recipes[i];
                ans.push_back(s);
                for (auto j : adj[s]) {
                    if (--deg[j] == 0) q.push(j);
                }
            }
            return ans;
        }
    };




    class Solution {
public:
    // tC -> O(N+M) , SC -> (N+M+S)
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // for o(1) lookup put all supplies in set
        // recipes depends on ingreadient so create adjacency list of string->vector<string> mapping each ingredient to list of recipes that needed it
        // indegree : string -> int for each recipe storing how many ingredients its waiting on

        unordered_set<string>available(supplies.begin(),supplies.end());
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>indegree;


        for(int i=0;i<recipes.size();i++){
            string recipe=recipes[i];
            int missingcnt=0;
            for(auto j:ingredients[i]){
                if(available.find(j)==available.end()){
                    adj[j].push_back(recipe);
                    missingcnt++;
                }
            }
            indegree[recipe]=missingcnt;
        }

        queue<string>q;
        for(auto &i:recipes){
            if(indegree[i]==0) q.push(i);
        }
        vector<string>ans;

        while(!q.empty()){
            string cur=q.front();
            q.pop();

            ans.push_back(cur);

            if(adj.count(cur)){
                for(auto &next:adj[cur]){
                    indegree[next]--;
                    if(indegree[next]==0) q.push(next);
                }
            }
        }

        return ans;
    }
};