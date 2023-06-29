class Solution {
    int hero(int ind, int buySell,vector<vector<int>> &dp, vector<int>& prices, int fee){
        if(ind == prices.size()) return 0;
        if(dp[buySell+1][ind] != -1)return dp[buySell+1][ind];
        if (buySell == -1){
            dp[buySell+1][ind] = max((-1 * prices[ind]) + hero(ind+1,0,dp,prices,fee), hero(ind+1,-1,dp,prices,fee));
        } else {
            if (buySell == 0) {
                dp[buySell+1][ind] = max(prices[ind] - fee +  hero(ind+1, 1,dp, prices,fee), hero(ind+1, 0,dp, prices,fee));
            } else {
                dp[buySell+1][ind]= max((-1 * prices[ind]) + hero(ind+1,0,dp,prices,fee), hero(ind+1,1,dp,prices,fee));
            }
        }
        return dp[buySell+1][ind];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(3, vector<int>(prices.size(),-1));
        return hero(0,-1,dp,prices, fee);
        // return dp[2][prices.size() - 1];
    }
};