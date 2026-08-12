class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<int> left(n, 0);
        vector<int> upperD(2 * n - 1, 0);
        vector<int> lowerD(2 * n - 1, 0);

        vector<string> board(n, string(n, '.'));

        function<void(int)> backtrack = [&](int row) {

            // All queens placed
            if (row == n) {
                ans.push_back(board);
                return;
            }

            for (int col = 0; col < n; col++) {

                // Check column
                if (left[col])
                    continue;

                // Check upper diagonal
                if (upperD[row + col])
                    continue;

                // Check lower diagonal
                if (lowerD[row - col + n - 1])
                    continue;

                // Place queen
                board[row][col] = 'Q';

                left[col] = 1;
                upperD[row + col] = 1;
                lowerD[row - col + n - 1] = 1;

                // Move to next row
                backtrack(row + 1);

                // Backtrack
                board[row][col] = '.';

                left[col] = 0;
                upperD[row + col] = 0;
                lowerD[row - col + n - 1] = 0;
            }
        };

        backtrack(0);

        return ans;
    }
};