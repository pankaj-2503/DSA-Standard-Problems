// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// Input: nums = [0,1]
// Output: 2

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
       
        int mx=0,sum=0;
        unordered_map<int,int>m; // sum as key and index as value where sum is encountered
        m[0]=-1;
        for(int i=0;i<n;i++){
           sum+=((nums[i]==1)?1:-1);
           
           if(m.find(sum)!=m.end()){
            mx=max(mx,i-m[sum]);
           }
           else m[sum]=i;
           
        }
        return mx;
    }
};