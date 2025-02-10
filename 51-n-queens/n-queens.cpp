class Solution {
public:
    bool isQueenPossible(int col, int row, vector<string> &board,int n){
        int dRow = row;
        int dCol = col;

        // to check upper diagnol
        while(row >= 0 && col >=0){
            if (board[row][col] ==  'Q') return false;
            row--;
            col--;
        }

        col = dCol;
        row = dRow;
        // to check left row and col
        while(col >=0){
            if (board[row][col] == 'Q') return false;
            col--;
        }

        col = dCol;
        row = dRow;
        // to check lower diagnol
        while(row<n && col >= 0){
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,int n){
        // we have to check whether the col is equals to n
        if (col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){

            // check if I can insert the queen
            if (isQueenPossible(col,row,board,n)){
                // insert the queen
                board[row][col] = 'Q';
                // make a function call
                solve(col+1,board,ans,n);
                // remove the queen for backtracking
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // define a data structure that stores our answer
        vector<vector<string>> ans;
        // define a chess board that is usually a row
        vector<string> board(n);
        string s(n,'.');
        // empty the board with .
        for(int i = 0; i<n; i++) board[i] =s;
        // make a function call
        solve(0,board,ans,n);
        return ans;
    }
};