// alice and bob are playing game , alice took first turn they could take max of M piles together and M is set every time after updates
// retur max no. of stones collected by alice

class Solution {
public:
    // Time complexity - O(N^3) , space complexity - O(N^2)
    int dp[1000][1000][2];
    int solve(int index,int m,vector<int>&piles,int turn,int n){
        if(index>=n) return 0;
        if(dp[index][m][turn]!=-1) return dp[index][m][turn];
        int sum=0;
        int ans=turn?INT_MIN:INT_MAX;
        for(int x=1;x<=min(2*m,n-index);x++){
            sum+=piles[index+x-1];
            if(turn==1){
                // maximise
                ans=max(ans,sum+solve(index+x,max(m,x),piles,1-turn,n));
            }else{
                // minimise
                ans=min(ans,solve(index+x,max(m,x),piles,1-turn,n));
            }
        }
        return dp[index][m][turn]= ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,piles,1,n); // index,m,piles,turn
    }
};