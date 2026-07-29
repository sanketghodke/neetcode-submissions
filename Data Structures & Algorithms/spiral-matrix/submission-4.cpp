class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        // right -- down -- left -- up

        int dir = 0;
        // o -> right , 1 -> down, 2 -> left, 3 -> up

        int left = 0;
        int top = 0;
        int down = n - 1;
        int right = m - 1;

        while (top <= down && left <= right) {
            if (dir == 0) {
                // print top row from left to right
                for (int i = left; i <= right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;

            } else if (dir == 1) {
                // print right column from top to down

                for (int i = top; i <= down; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;

            } else if (dir == 2) {
                // print down row from right to left
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;

            } else if (dir == 3) {
                // print left column from down to top
                for (int i = down; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;

            } 
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
