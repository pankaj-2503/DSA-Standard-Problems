class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        //four movements
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        // {diff,{row,col}} -> priority queue
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        // dist array 
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        // dist of source marked as 0 and pushed into queue
        dist[0][0]=0;
        pq.push({0,{0,0}}); // {diff,row,col}

        while(!pq.empty()){
            auto top=pq.top();
            int dif=top.first;
            int row=top.second.first;
            int col=top.second.second;
            pq.pop();

            if(row==n-1 && col==m-1) return dif;

            for(int i=0;i<4;i++){
                int nrow=x[i]+row;
                int ncol=y[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neweffort=max(abs(heights[row][col]-heights[nrow][ncol]),dif);
                    if(neweffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};