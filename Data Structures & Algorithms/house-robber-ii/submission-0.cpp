class Solution {
public:
    int recc(int ind, int low, vector<int>& nums, vector<int>& dp) {

        if (ind == low) return nums[ind];
        if (ind < low) return 0;

        if (dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + recc(ind - 2, low, nums, dp);
        int notPick = recc(ind - 1, low, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(
            recc(n - 2, 0, nums, dp1),
            recc(n - 1, 1, nums, dp2)
        );
    }
};