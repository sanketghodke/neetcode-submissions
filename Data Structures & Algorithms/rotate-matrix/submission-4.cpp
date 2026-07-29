class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        // 0,0 0,1
        // 1,0 1,1
        // first take transpose of a matrix

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse all elements
        for (int i =0 ; i< n ; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
