class Solution {
public:
    // Time complexity - O(N) , SC - O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double cur=0;
        for(int i=0;i<k;i++) cur+=nums[i];
        double mx=cur/k;

        for(int i=k;i<n;i++){
            cur+=nums[i];
            cur-=nums[i-k];
            mx=max(mx,cur/k);
        }
        return mx;
    }
};