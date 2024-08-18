// tC-> O(NlogN)
int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:arr) pq.push(i);
        int top=-1;
        while(k--){
            top=pq.top();
            pq.pop();
        }
        return top;
    }