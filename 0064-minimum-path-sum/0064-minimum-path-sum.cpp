class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0 || j<0)
            return INT_MAX;
        int up=INT_MAX,left=INT_MAX;
        if(i>=1){
        up=grid[i][j]+solve(i-1,j,grid,dp);
        }
        if(j>=1){
        left=grid[i][j]+solve(i,j-1,grid,dp);
        }
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int a=grid.size();
        int b=grid[0].size();
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return solve(a-1,b-1,grid,dp);
    }
};