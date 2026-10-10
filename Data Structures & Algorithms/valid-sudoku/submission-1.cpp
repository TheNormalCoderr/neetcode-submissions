class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int n, int i, int j){
        // Check the row 
        for(int col = 0; col < n; ++col){
            if(board[i][col] == board[i][j] && col != j) return false;
        }
        // Check the col
        for(int row = 0; row < n; ++row){
            if(board[row][j] == board[i][j] && row != i) return false;
        }
        // Check 3x3 box
        int startRow = i - i % 3;
        int startCol = j - j % 3;
        for(int row = startRow; row < startRow + 3; ++row){
            for(int col = startCol; col < startCol + 3; ++col){
                if(board[row][col] == board[i][j] && row != i && col != j) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < n; ++col){
                if(board[row][col] != '.'){
                    if(!isSafe(board, n, row, col)) return false;
                }
            }
        }
        return true;
    }
};
