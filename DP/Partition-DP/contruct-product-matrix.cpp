#define ll long long
const ll mod = 12345;
class Solution {
public:
    // TC -> O(N*M), same sC
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>p(n,vector<int>(m));

        ll suffix=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                p[i][j]=suffix;
                suffix=grid[i][j]*suffix %mod;
            }
        }
        ll prefix=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p[i][j]= prefix*p[i][j]%mod;
                prefix=prefix*grid[i][j]%mod;
            }
        }
        return p;
    }
};


// this problem is same as product of array except itself but for 2d array
// which has code like this
class Solution {
public:
// tC -> O(n),same sc
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        int left=1;
        for(int i=0;i<n;i++){
            ans[i]*=left;
            left*=nums[i];
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=right;
            right*=nums[i];
        }
        return ans;

    }
};