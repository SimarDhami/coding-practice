class Solution {
public:
    int climbStairs(int n) {
        int prev=1;
        int prev2=1;
        int curr=0;
        if(n<=2)
            return n;
        for(int i=2;i<=n;i++){
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};