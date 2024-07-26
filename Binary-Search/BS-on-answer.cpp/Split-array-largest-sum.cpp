#define ll long long
class Solution {
public:
    int solve(vector<int>&a,int k,int mid){
        int sum=0,cnt=1;
        for(int i=0;i<a.size();i++){
            if(sum+a[i]<=mid) sum+=a[i];
            else{
                sum=a[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        ll n=nums.size();
        ll low=*max_element(nums.begin(),nums.end());
        ll high=accumulate(nums.begin(),nums.end(),0ll);
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            ll val=solve(nums,k,mid);
            if(val>k) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};