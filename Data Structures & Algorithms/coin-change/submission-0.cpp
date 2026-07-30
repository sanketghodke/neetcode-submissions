class Solution {
   public:
    int recc(int ind, int amount, vector<int>& coins) {
        if (ind == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }
        // pick 10
        int pick = INT_MAX;
        if (coins[ind] <= amount) {
            pick = 1 + recc(ind, amount - coins[ind], coins);
        }

        // pick not 10
        int notPick = 0 + recc(ind - 1, amount, coins);

        return min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) { 
        
       int  ans = recc(coins.size() - 1, amount, coins); 
        return (ans >= 1e9) ? -1 : ans;
        }
};
