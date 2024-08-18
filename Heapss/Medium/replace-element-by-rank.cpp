
    // TC: O(NlogN) ,SC:O(N)
    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<N;i++) pq.push({-arr[i],i});
        int rank=0,prev=-1;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            
            if(-t.first!=prev) rank++;
            
            arr[t.second]=rank;
            prev=-t.first;
            
        }
        return arr;
    }
