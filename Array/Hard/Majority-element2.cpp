class Solution {
public:
// TC: O(N) , sC: O(n)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        int n=nums.size();
        vector<int>ans;
        for(auto i:m){
            if(i.second>n/3) ans.push_back(i.first);
        }
        return ans;
    }
};