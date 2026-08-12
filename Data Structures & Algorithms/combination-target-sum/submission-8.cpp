class Solution {
public:
    void recc(int ind, int sum, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums, int target){
        if (sum > target)
            return;

        if(ind == nums.size()){
            if(sum == target) ans.push_back(temp);
            return;
        }

        //take condition

        sum = sum + nums[ind];
        temp.push_back(nums[ind]);
        recc(ind, sum, temp, ans, nums, target);

        // not take condition
        
        sum = sum - nums[ind];
        temp.pop_back();
        recc(ind+1, sum, temp, ans, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        // similar to take and not take , we were incrementing the integer, here we will not do that
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        recc(0, sum, temp, ans, nums, target);
        return ans;
    }
};
