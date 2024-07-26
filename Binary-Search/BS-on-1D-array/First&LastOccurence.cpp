class Solution {
public:
    int firstOccur(vector<int>&nums,int target){
        int n=nums.size();
        int low=0,high=n-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    int lastOccur(vector<int>&nums,int target){
         int n=nums.size();
         int low=0,high=n-1,ans=-1;
         while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else low=mid+1;
         }
         return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int f=firstOccur(nums,target);
        int l=lastOccur(nums,target);
        return {f,l};

    }
};