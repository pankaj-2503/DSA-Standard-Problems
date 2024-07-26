#define ll long long 
class Solution {
public:
   // Time complexity - O(N*log(high-low))
    bool ispossible(vector<int>&a,int mid,int days){
        int cnt=1,total=0;
        for(int i=0;i<a.size();i++){
            if(total+a[i]>mid){
                cnt++;
                total=a[i];
            }
            else
            total+=a[i];
        }
        if(cnt<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        ll n=weights.size();
        ll low=*max_element(weights.begin(),weights.end());
        ll high=accumulate(weights.begin(),weights.end(),0ll);
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            bool val=ispossible(weights,mid,days);
            if(val==false) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};