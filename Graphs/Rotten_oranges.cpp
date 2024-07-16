class Solution {
public:
// Time Complexity: O ( n x n ) x 4 , Space Complexity: O ( n x n )
    int orangesRotting(vector<vector<int>>& grid) {
        int total=0,cnt=0,days=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }

        int delrows[]={-1,0,1,0};
        int delcols[]={0,-1,0,1};

        while(!q.empty()){
            int s = q.size();
            cnt+=s;
            while(s--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + delrows[i];
                    int ny = y + delcols[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) days++;
        }
        return total==cnt?days:-1;
    }
};