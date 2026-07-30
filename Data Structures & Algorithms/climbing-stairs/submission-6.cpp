class Solution {
   public:
    int recc(int ind, vector<int>& dp) {
        if (ind <= 1) return 1;
        if (dp[ind]!=-1) return dp[ind];
        return dp[ind] = recc(ind - 1, dp) + recc(ind - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return recc(n, dp);
    }
};
