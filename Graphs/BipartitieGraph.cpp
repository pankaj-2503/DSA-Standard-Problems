class Solution {
public:
    bool dfs(int node,int col,int color[],vector<vector<int>>&graph){
        color[node]=col;
        for(auto j:graph[node]){
            if(color[j]==-1){
               if(dfs(j,!col,color,graph)==false) return false; 
            }
            //previously colored with same color
            else if(color[j]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        int color[v];
        for(int i=0;i<v;i++) color[i]=-1;
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};