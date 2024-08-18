class Solution {
public:
// TC: O(NlogN + KlogN) , SC: O(N)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto i:nums) pq.push(i);
        int top=INT_MIN;
        while(k--){
            top=pq.top();
            pq.pop();
        }
        return top;
    }
};