class Solution {
public: 
    // Time complexity - O(N!*N) , sapce complexity - O(N)
    bool isSafe(int row,int col,vector<string>board,int n){
         int duprow=row,dupcol=col;
         // check previous diagonally upper
         while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            else{
                row--;col--;
            }
         }
         // check previous diagonally lower
         row=duprow;
         col=dupcol;
         while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            else{
                row++;col--;
            }
         }
         // check previous horizontally
         row=duprow;
         col=dupcol;
         while(col>=0){
            if(board[row][col]=='Q') return false;
            else col--;
         }
         return true;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){//base case
            ans.push_back(board);
            return;
        }
        // try all row for given col where isSafe to put queen
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.'; //backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n); //vector of string
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        int col=0;
        solve(col,board,ans,n);
        return ans;
    }
};