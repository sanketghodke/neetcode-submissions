class Solution {
public:
    int recc(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return dp[ind] = nums[ind];
        if(ind <0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + recc(ind - 2, nums,dp);
        int notPick = 0 + recc(ind-1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recc(nums.size()-1 , nums, dp);
        
    }
};
