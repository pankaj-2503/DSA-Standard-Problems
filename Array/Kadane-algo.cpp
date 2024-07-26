class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int mxsum=nums[0];
       int cursum=nums[0];
        for(int i=1;i<nums.size();i++){
            cursum=max(cursum+nums[i],nums[i]);
            mxsum=max(mxsum,cursum);
           
        }
        return mxsum;
    }
};


int maxSubArray(vector<int>& nums) {
       int mxsum=INT_MIN;
       int cursum=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            mxsum=max(mxsum,cursum);
            if(cursum<0) cursum=0;
           
        }
        return mxsum;
    }