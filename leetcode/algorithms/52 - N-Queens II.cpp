class Solution {
    
    int backtrack(int row, int n, int cnt, vector<int>& cols, vector<int>& mainDiagonal, vector<int>& reverseDiagonal) {
        for (int col = 0; col < n; col++) {
            if (cellIsFree(row, col, n, cols, mainDiagonal, reverseDiagonal)) {
                cols[col] = 1;
                mainDiagonal[row - col + n] = 1;
                reverseDiagonal[row + col] = 1;
                
                if (row + 1 == n) {
                    cnt++;
                }
                else {
                    cnt = backtrack(row + 1, n, cnt, cols, mainDiagonal, reverseDiagonal);
                }
                
                cols[col] = 0;
                mainDiagonal[row - col + n] = 0;
                reverseDiagonal[row + col] = 0;
            }
        }
        
        return cnt;
    }
    
    bool cellIsFree(int row, int col, int n, vector<int>& cols, vector<int>& mainDiagonal, vector<int>& reverseDiagonal) {
        int res = cols[col] + mainDiagonal[row - col + n] + reverseDiagonal[row + col];
        return res == 0;
    }
    
public:
    int totalNQueens(int n) {
        vector<int> cols(n, 0), mainDiagonal(2 * n, 0), reverseDiagonal(2 * n, 0);
        return backtrack(0, n, 0, cols, mainDiagonal, reverseDiagonal);
    }
};