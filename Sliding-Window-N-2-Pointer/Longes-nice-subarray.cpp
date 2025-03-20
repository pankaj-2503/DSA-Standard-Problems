class Solution {
    public:
        // TC: O(n), SC: O(1)
        int longestNiceSubarray(vector<int>& nums) {
            int mxlen=1;
            int n=nums.size();
            int left=0,right=0,used=0;
            while(right<n){
                while((nums[right]&used)!=0){
                    used^=nums[left]; // removing left part as xor removes duplicates
                    left++;
                }
                used|=nums[right];  // this sets current number to used for next check
                mxlen=max(mxlen,right-left+1);
                right++;
            }
            return mxlen;
        }
    };