class Solution {
public:
    void recc(int ind, vector<int>& nums,vector<int>& temp, vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        recc(ind+1, nums, temp, ans);

        temp.pop_back();
        recc(ind+1, nums, temp, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        recc(0, nums,temp, ans);
        return ans;
    }
};
