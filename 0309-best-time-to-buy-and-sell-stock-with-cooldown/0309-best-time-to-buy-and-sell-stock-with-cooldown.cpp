class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if(ind >= n)
            return 0;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        if(buy) {
            int take = f(ind + 1, 0, prices, n, dp) - prices[ind];
            int notTake = f(ind + 1, 1, prices, n, dp);

            return dp[ind][buy] = max(take, notTake);
        }

        int sell = f(ind + 2, 1, prices, n, dp) + prices[ind];
        int notSell = f(ind + 1, 0, prices, n, dp);

        return dp[ind][buy] = max(sell, notSell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, dp);
    }
};