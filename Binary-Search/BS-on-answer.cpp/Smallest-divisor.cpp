#define ll long long
class Solution {
public:
    bool ispossible(vector<int>&a,int threshold,int mid){
        ll sum=0;
        for(int i=0;i<a.size();i++){
            sum+=(a[i]+mid-1)/mid;
        }
        if(sum<=threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        ll low=1;
        ll high=*max_element(nums.begin(),nums.end());
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            bool val=ispossible(nums,threshold,mid);
            if(val==false) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};