class Solution {
public:
// TC: O(N^2logN) , SC: O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int low=i+1,high=n-1;
            while(low<high){
                int ans=nums[i]+nums[low]+nums[high];
                if(ans==0){
                    s.insert({nums[i],nums[low],nums[high]});
                    low++;high--;
                }
                else if(ans<0) low++;
                else high--;
            }

        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};