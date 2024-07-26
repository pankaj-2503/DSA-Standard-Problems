#define ll long long
class Solution {
public:
    bool isPossible(vector<int>&a,int mid,int k,int m){
        ll cnt=0,noOfBouquet=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=mid) cnt++;
            else{
                noOfBouquet+=cnt/k;
                cnt=0;
            }
        }
        noOfBouquet+=cnt/k;
        if(noOfBouquet>=m) return true;
        else return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Time complexity - O(N*log(high-low+1))
        ll n=bloomDay.size();
        ll low=*min_element(bloomDay.begin(),bloomDay.end());
        ll high=*max_element(bloomDay.begin(),bloomDay.end());
        ll ans=0;
        ll total=m,consecutive=k;
        if(total*consecutive>n) return -1;
        while(low<=high){
            ll mid=low+(high-low)/2;
            bool val=isPossible(bloomDay,mid,k,m);
            if(val==false) low=mid+1;
            else{
                ans=mid;high=mid-1;
            }
        }
        return ans;
    }
};