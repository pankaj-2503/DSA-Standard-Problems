class Solution {
public:
    // TC -> O(nlogn + n^2*logn),SC->O(N)
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>>s;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }else if(sum<0) j++;
                else k--;
            }
        }
        for(auto i:s) ans.push_back(i);
        return ans;

    }
};


// TC -> O(N^2logk + O(nlogn))
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<tuple<int,int,int>>s;
        vector<vector<int>>ans;

        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    s.insert(make_tuple(nums[i],nums[j],nums[k]));
                    j++;k--;
                }else if(sum<0) j++;
                else k--;
            }

        }

        for(auto &[a,b,c]:s){
            ans.push_back({a,b,c});
        }
        return ans;
    }
};


// TC -> O(N^2)'

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>ans;

        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // skip duplicates
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    // skip duplicate
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;k--;
                }else if(sum<0) j++;
                else k--;
            }

        }


        return ans;
    }
};