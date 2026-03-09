class Solution {
public:
    // TC -> O(N) , SC -> O(1)
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,mx=0;
        unordered_map<int,int>m;
        while(r<n){
            m[nums[r]]++;
            while(m[0]>k){
                m[nums[l]]--;
                l++;
            }
            mx=max(mx,r-l+1);
            cout<<mx<<endl;
            r++;
        }
        return mx;
    }
};