

class Solution {
public:
    // TC -> O(N) , SC -O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int mn=INT_MAX,sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                mn=min(mn,r-l+1);
                sum-=nums[l];
                l++;
            }
           r++;


        }
        return mn==INT_MAX?0:mn;
    }
};