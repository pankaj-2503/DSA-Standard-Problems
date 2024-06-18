class Solution {
public:
// Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board,
//  we have 9 possible numbers.
// Space complexity - O(1)
   bool canPlace(vector<vector<char>>& board, int i, int j, char num) {
        for (int idx = 0; idx < 9; idx++) {
            
            if (board[i][idx] == num) return false;
            if (board[idx][j] == num) return false;
            if (board[(i/3)*3 + (idx/3)][(j/3)*3 + (idx%3)] == num) return false;
        }
        
        return true;
    }
   bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') {
                    
                    // Try each number, if canPlace - go on with recursion
                    for (char num = '1'; num <= '9'; num++) {
                        
                        if (canPlace(board, i, j, num)) {
                            board[i][j] = num;
                            if (backtrack(board)) 
                                return true;
                            
                            board[i][j] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       backTrack(board);
    }
};