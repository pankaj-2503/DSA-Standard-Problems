// Time Complexity : O(100000 * N) , same SC
int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q; // {distance,node}
        q.push({0,start});
        
        vector<int>dis(100000,1e9);
        dis[start]=0;
        
        while(!q.empty()){
            int steps=q.front().first;
            int val=q.front().second;
            q.pop();
            
            if(val==end)return steps;
            
            
            for(auto it:arr){
               int num=(it*val)%100000;
               if(steps+1<dis[num]){
                   dis[num]=steps+1;
                   q.push({steps+1,num});
               }    
            }
        }
        
        return -1;
        
    }