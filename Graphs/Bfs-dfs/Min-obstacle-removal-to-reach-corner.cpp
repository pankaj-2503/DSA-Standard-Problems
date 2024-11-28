class Solution {
public:
    // T.C : ->O(N*M) , same SC
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // we are considering each value in matrix as node of graph
        // running bfs on this graph using deque to maintain order 
        // since 0 would not be added to shortest distance
        // those with blocked ones would contribute to answer 
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};

        while(!dq.empty()){
            auto [x,y]=dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

                int newDist=dist[x][y]+grid[nx][ny];
                if(newDist<dist[nx][ny]){
                    dist[nx][ny]=newDist;
                    if(grid[nx][ny]==0){
                        dq.push_front({nx,ny});
                    }else{
                        dq.push_back({nx,ny});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};