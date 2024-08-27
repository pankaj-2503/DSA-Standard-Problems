class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int step=nums[0];
        for(int i=1;i<n;i++){
            step--;
            if(step<0) return false;
            else if(nums[i]>step) step=nums[i];
        }
       
        return true;
    }
};