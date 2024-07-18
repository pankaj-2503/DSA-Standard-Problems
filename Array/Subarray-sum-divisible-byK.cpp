class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int remainder=sum%k;
            if(remainder<0) remainder+=k;
            cnt+=m[remainder];
            m[remainder]++;
        }
        return cnt;
    }
};