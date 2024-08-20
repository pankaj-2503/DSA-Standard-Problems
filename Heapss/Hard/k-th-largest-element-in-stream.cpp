class KthLargest {
public:
// TC: O(NlogN) , SC: O(N)
    int num;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        num=k;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>num) pq.pop();
        return pq.top();
    }
};
