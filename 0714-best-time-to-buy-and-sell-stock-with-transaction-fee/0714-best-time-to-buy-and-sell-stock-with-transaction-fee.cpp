class Solution {
public:
    int solve( vector<int> &prices, int i, int b, int fee, vector<vector<int>> &dp ) {
        if( i == prices.size() )
            return 0;
        if( dp[i][b] != INT_MIN )
            return dp[i][b];
        
        if( b ) {
            dp[i][b] = max( solve(prices, i+1, b, fee, dp ), 
                            -prices[i] + solve(prices, i+1, !b, fee, dp ) );
        }
        else {
            dp[i][b] = max( solve(prices, i+1, b, fee, dp ), 
                            prices[i]-fee + solve(prices, i+1, !b, fee, dp ) );
        }
        return dp[i][b];
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp( prices.size(), vector<int>( 2, INT_MIN ) );
        return solve( prices, 0, 1, fee, dp );
    }
};