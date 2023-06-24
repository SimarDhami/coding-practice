
class Solution {
public:
         
    int minFallingPathSum(vector<vector<int>>& Matrix) {
    int N =Matrix.size();
    vector<vector<int>> dp(N, vector<int>(N, -1));
    
    for(int i=0;i<N;i++)
    {
        dp[0][i]=Matrix[0][i];
    } 
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int minm=dp[i-1][j];
            if(j>0)
            {
                minm=min(minm,dp[i-1][j-1]);
            }
            if(j<(N-1))
            {
                minm=min(minm,dp[i-1][j+1]);

            }
            dp[i][j]=Matrix[i][j]+minm;
        }
    }
    int minm=INT_MAX;
    for(int i=0;i<N;i++)
    {
        minm=min(minm,dp[N-1][i]);
    }
    return minm;
    }
};