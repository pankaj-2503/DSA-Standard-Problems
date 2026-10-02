class Solution {
public:
    // TC -> O(M*N) same sc
    int dfs(vector<vector<int>>&grid,int i,int j){
        int n=grid.size(),m=grid[0].size();
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0 ) return 0;
        grid[i][j]=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int cnt=0;
        for(int k=0;k<4;k++){
            cnt+=dfs(grid,i+dx[k],j+dy[k]);
        }
        return 1+cnt;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 ){
                    int area=dfs(grid,i,j);
                    mx=max(mx,area);
                }
            }
        }
        return mx;
    }
};