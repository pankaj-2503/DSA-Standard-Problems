class Solution {
public:
// Time complexity - O(N) , space complexity - O(1)

    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0;
        int zeros=0,len=0;
        // langest subarray with atmost k 0's
        while(right<n){
           if(nums[right]==0) zeros++;
            if(zeros>k){
                if(nums[left]==0) zeros--;
                left++;
            }
            if(zeros<=k) len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};

class Solution {
public:
// Time complexity - O(N)+O(N) , space complexity - O(1)

    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0;
        int zeros=0,len=0;
        // langest subarray with atmost k 0's
        while(right<n){
           if(nums[right]==0) zeros++;
            while(zeros>k){
               if(nums[left]==0) zeros--;
               left++;
                
            }
            if(zeros<=k) len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};