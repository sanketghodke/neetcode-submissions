class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> col;
        unordered_map<int, unordered_set<char>> row;
        map<pair<int, int>, unordered_set<char>> square;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;

                pair<int, int> squarekey = {i / 3, j / 3};

                if (row[i].count(board[i][j]) || col[j].count(board[i][j]) ||
                    square[squarekey].count(board[i][j])){
                        return false;
                    }
                
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                square[squarekey].insert(board[i][j]);
                            }
        }
        return true;
    }

};
