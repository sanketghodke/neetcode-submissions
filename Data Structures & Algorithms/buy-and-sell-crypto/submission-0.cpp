class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int sell = INT_MIN;
        // profit = sell - cost
        for(int i=prices.size()-1; i>=0; i--){
            sell= max(prices[i],sell);
            if(sell != prices[i]){
                profit = max(profit, (sell-prices[i]));
            }
        }
        return profit;
    }
};
