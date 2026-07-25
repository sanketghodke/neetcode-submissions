class Solution {
public:

void findCombinations(int index, vector<int>& combination, vector<vector<int>>& ans,
                          vector<int>& candidates) {
        if (index == candidates.size()) {
            ans.push_back(combination);
            return;
        }

        // take condition

        
        combination.push_back(candidates[index]);
        findCombinations(index + 1, combination, ans, candidates);

       
        combination.pop_back();
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        findCombinations(index + 1, combination, ans, candidates);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(nums.begin(), nums.end());
        findCombinations(0, combination, ans, nums);
        return ans;
    }
};
