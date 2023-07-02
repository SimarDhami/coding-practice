class Solution {
public:
    bool solve(string &s,string& p,int i,int j,vector<vector<int>>& dp){
        //base case
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        //Recursive Case
        if(dp[i][j]!=(-1)){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]=(solve(s,p,i,j-1,dp)||solve(s,p,i-1,j,dp));
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int slen=s.length(),plen=p.length();
        vector<vector<int>> dp(slen,vector<int>(plen,-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }
};