class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // make a function call 
        solve(board);
    }
    bool solve(vector<vector<char>> &board){

        for(int row = 0; row<board.size(); row++){
            for(int col =0; col<board[0].size(); col++){

                // check if the cell is empty or not
                if (board[row][col]=='.'){

                    for(char ch='1'; ch<='9';ch++){

                        // check whether we can place the value in the particular cell or not
                        if (isValid(board,row,col,ch)){
                            // insert the value
                            board[row][col] = ch;

                            // check if the sudoko is filled or not by making function calls
                            if (solve(board) == true) return true;
                            // after inserting if it doesn't satisfy all the conditions then make it as empty
                            else board[row][col] = '.';
                        }
                    }
                    // if the value is not fit then return false.
                    return false;
                }
            }
        }
        // return true if all the values are satisfied.
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char ch){

        for(int i = 0; i<9; i++){
            // check for constant row and changing column
            if (board[row][i] == ch) return false;
            // check for constant column and changing row
            if(board[i][col] == ch)  return false;
            // check for inner 3x3 matrix (meaning the inner boxes for values)
            if (board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == ch) return false;
        }
        return true;
    }
};