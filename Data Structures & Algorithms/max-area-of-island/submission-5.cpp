class Solution {
   public:
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int area = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int drow = row + dr[i];
                int dcol = col + dc[i];

                if (drow >= 0 && drow < n && dcol >= 0 && dcol < m && !vis[drow][dcol] &&
                    grid[drow][dcol] == 1) {
                    vis[drow][dcol] = 1;
                    q.push({drow, dcol});
                    area = area + 1;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    int area = bfs(i, j, grid, vis);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
