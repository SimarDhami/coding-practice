class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i>=0 &&j>=0 && grid[i][j]==1)
            return 0;
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down=solve(i-1,j,grid,dp);
        int left=solve(i,j-1,grid,dp);
        
        return dp[i][j]=left+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int a=grid.size();
        int b=grid[0].size();
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return solve(a-1,b-1,grid,dp);
    }
};