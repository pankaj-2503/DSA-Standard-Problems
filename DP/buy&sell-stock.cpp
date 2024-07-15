class Solution {
public:
// Time complexity - O(N) ,space complexity - constant
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int mxProfit=0;
        for(int i=1;i<n;i++){
            int curProfit=prices[i]-mini;
            mxProfit=max(mxProfit,curProfit);
            mini=min(mini,prices[i]);
        }
        return mxProfit;

    }
};