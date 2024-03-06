// 37. Sudoku Solver

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(int n=1; n<= 9; n++) {
                        char cn = to_string(n).c_str()[0];
                        if (possible(board, row, col, cn)) {
                            board[row][col] = cn;
                            if (solve(board)) {
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool possible(vector<vector<char>>& board, int y, int x, char n) {
        // check in row
        for(int i = 0; i < 9; i++) {
            if (board[i][x] == n) {
                return false;
            }
            if (board[y][i] == n) {
                return false;
            }
        }

        // check in col
        for(int col = 0; col < 9; col++) {
            
        }

        int x0 = x - x % 3;
        int y0 = y - y % 3;

        for(int row = 0; row < 3; row++) {
            for(int col = 0; col < 3; col++) {
                if (board[y0+row][x0+col] == n) {
                    return false;
                }
            }
        }

        return true;
    }
};
