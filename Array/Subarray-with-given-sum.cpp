class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        int cnt=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m[sum-k]>0) cnt+=m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};