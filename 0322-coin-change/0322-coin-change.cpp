class Solution {
public:
    int solve(int i,vector<int>&coins, int amount,vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[i]==0){
                return amount/coins[i];
            }
            else
                return 1e9;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int nopick=0+solve(i-1,coins,amount,dp);
        int pick=1e9;
        if(amount>=coins[i]){
        pick=1+solve(i,coins,amount-coins[i],dp);
    }
        return dp[i][amount]=min(nopick,pick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,coins,amount,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};