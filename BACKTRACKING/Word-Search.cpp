class Solution {
public:
    // Time Complexity:  O(m*n*4^k), Space complexity - O(K)-> length of word
    bool solve(int row,int col,int n,int m,vector<vector<char>>&board,string word,int index){
          if(index==word.size()) return true;
          if(row<0 || col<0 || row==n || col==m || board[row][col]!=word[index]) return false;
          char ch=board[row][col];
          board[row][col]='#';
          bool up=solve(row-1,col,n,m,board,word,index+1);
          bool down=solve(row+1,col,n,m,board,word,index+1);
          bool left=solve(row,col-1,n,m,board,word,index+1);
          bool right=solve(row,col+1,n,m,board,word,index+1);
          board[row][col]=ch;

          return up|down|left|right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(i,j,n,m,board,word,index)) return true;
            }
        }
        return false;
    }
};