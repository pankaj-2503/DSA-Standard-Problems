class Solution {
public:
// TC: O(N*shelfwidth) , SC: O(N*shelfwidth)+O(N)
    int solve(int ind, vector<vector<int>>& books, int remWidth, int maxH, int shelfWidth, vector<vector<int>>& dp){
        //basecase
        if(ind>=books.size()) return maxH;

        if(dp[ind][remWidth]!=-1) return dp[ind][remWidth];

         int bookT = books[ind][0];
         int bookH = books[ind][1];
        //if i keep
        int pick = INT_MAX; 
        if(bookT<=remWidth) pick = solve(ind+1, books, remWidth-bookT, max(maxH, bookH), shelfWidth, dp);
        
        //if i not keep
        int notpick = INT_MAX;
        notpick = maxH + solve(ind+1, books, shelfWidth-bookT, bookH, shelfWidth, dp);

        return dp[ind][remWidth] = min(pick,notpick) ;
        
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth+1,-1));
        int remWidth = shelfWidth;
        return solve(0, books, remWidth, 0, shelfWidth, dp);
    }
};


// Tabulation -> TC: O(N*shelfwidth) , SC: O(N)
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        // dp[i] represent minimum height required to place i books on shelves
        int dp[n+1];
        dp[0]=0; // since 0 books required 0 height;
        for(int i=1;i<=n;i++){
            int w=books[i-1][0];
            int h=books[i-1][1];
            dp[i]=dp[i-1]+h;
            for(int j=i-1;j>0;j--){
                w+=books[j-1][0];
                if(w>shelfWidth) break;
                h=max(h,books[j-1][1]);
                dp[i]=min(dp[i],dp[j-1]+h);
            }
        }
        return dp[n];
    }
};