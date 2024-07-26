class Solution {
public:
    long long solve(vector<int>&a,int mid,int h){
        long long ans=0;
        for(auto i:a){
            ans+=ceil((double)i/mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long mx=*max_element(piles.begin(),piles.end());
        long long low=1,high=mx;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long val=solve(piles,mid,h);
            if(val<=h){
                ans=mid;high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};