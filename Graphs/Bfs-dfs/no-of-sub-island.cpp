class Solution {
public:
// TC: O(M*N) , SC:O(1)
    bool island=true;
    int n,m;
    void dfs(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>&grid2){
        if(grid1[i][j]!=grid2[i][j]) island=false;
        grid2[i][j]=0;
        grid1[i][j]=0;
        int a[]={0,0,1,-1};
        int b[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int x=a[k]+i;
            int y=b[k]+j;

            if(x>=0 && x<n && y>=0 && y<m && grid2[x][y]==1) dfs(x,y,grid1,grid2);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt=0;
         n=grid2.size();
         m=grid2[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    island=true;
                    dfs(i,j,grid1,grid2);
                    if(island) cnt++;
                }
            }
        }
        return cnt;
    }
};