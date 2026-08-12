class Solution {
   public:
    void findCombinations(int index, int sum, vector<int>& combination, vector<vector<int>>& ans,
                          vector<int>& candidates, int target) {
        if (sum > target) return;

        if (index == candidates.size()) {
            if (sum == target) ans.push_back(combination);
            return;
        }

        // take condition

        sum = sum + candidates[index];
        combination.push_back(candidates[index]);
        findCombinations(index + 1, sum, combination, ans, candidates, target);

        sum = sum - candidates[index];
        combination.pop_back();
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        findCombinations(index + 1, sum, combination, ans, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        findCombinations(0, 0, combination, ans, candidates, target);
        return ans;
    }
};
