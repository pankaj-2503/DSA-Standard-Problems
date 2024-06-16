class Solution {
public:
// time complexity - O(logn +m) , space complexity - O(1)
    int minPatches(vector<int>& nums, int n) {
         long long miss=1;
         long long ans=0;
         int i=0;
         while(miss<=n){
            if(i<nums.size() && nums[i]<=miss){
                miss+=nums[i];i++;
            }else{
                miss+=miss;
                ans++;
            }
           cout<<miss<<' '<<ans<<"-";
         }
         return ans;
    }
};