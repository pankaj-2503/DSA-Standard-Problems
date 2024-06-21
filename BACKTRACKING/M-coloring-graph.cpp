class Solution{
    bool possible(int node,int color[],bool graph[101][101],int n,int col){
        for(int k=0;k<n;k++){
            if(color[k]==col && graph[k][node]==1 && k!=node ) return false;
        }
        return true;
    }
    bool solve(int node,int m,int n,bool graph[101][101],int color[]){
         if(node==n) return true;
         for(int col=1;col<=m;col++){
             if(possible(node,color,graph,n,col)){
                 color[node]=col;
                 if(solve(node+1,m,n,graph,color)) return true;
                 color[node]=0;
             }
         }
         return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
         // your code here
         int color[n]={0};
         if(solve(0,m,n,graph,color)) return true;
         return false;
    }
};