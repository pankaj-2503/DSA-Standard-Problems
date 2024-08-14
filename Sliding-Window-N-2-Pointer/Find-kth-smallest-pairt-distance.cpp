class Solution {
public:
// TC: O(NlogM + NLogN) -> where N is no. of elements and M is maximum difference
    int countPairs(vector<int>&nums,int mid){
        int cnt=0;
        int n=nums.size();
        int left=0,right=0;
        while(right<n){
            // adjust left if distance b/w right and left is greater then maxdistance
            while(nums[right]-nums[left]>mid) left++;
            // no. of valid pairs ending at right
            cnt+=right-left;
            right++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=nums[n-1]-nums[0];

        while(low<high){
            int mid=(low+high)/2;
            // cnt pair with distance less than or equal to mid
            int cnt=countPairs(nums,mid);

            if(cnt<k){
                low=mid+1;
            }else high=mid;
        }
        return low;

    }
};