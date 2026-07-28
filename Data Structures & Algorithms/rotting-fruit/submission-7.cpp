class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshCount = 0;
        vector<vector<int>> ans = grid;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // {{r,c},t}
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }
        // up - right - down - left
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        int maxTime = 0;

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxTime = max(maxTime, time);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] &&
                    ans[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time + 1});
                    freshCount--;
                    vis[nrow][ncol] = 2;
                    ans[nrow][ncol] = 2;
                }
            }
        }
        if(freshCount != 0){
            return -1;
        }
        else{
            return maxTime;
        }
        
    }
};
