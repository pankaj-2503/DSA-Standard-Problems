#define ll long long
class Solution {
public:
    // Brute force is 2 loop n*k and find max sum
    // TC -> O(n), SC -> O(k)
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n=nums.size();
        ll sum=0,mx=0;
        unordered_set<int>s;
        int i=0,j=0;
        while(j<n){

            while(s.find(nums[j])!=s.end()){
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }

            sum+=nums[j];
            s.insert(nums[j]);

            if(j-i+1>k){
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }

            if(j-i+1==k){
                mx=max(mx,sum);
            }
            j++;

        }
        return mx;
    }
};