class Solution {
public:
// TC: O(nlogn+k*logn)  , SC: O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:m){
           pq.push({i.second,i.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};