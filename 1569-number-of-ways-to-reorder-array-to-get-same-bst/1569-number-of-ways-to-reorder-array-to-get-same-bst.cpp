class Solution {
public:

    long long mod = 1e9 + 7;
    vector<vector<long long>> table;

    long long dfs(vector<int> &nums){

        int n = nums.size();
        if(n<=2)    return 1;

        vector<int> lt, rt;
        //Store the values lesser and greater than the root in different arrays
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[0]) lt.push_back(nums[i]);
            else rt.push_back(nums[i]);
        }
        
        long long left = dfs(lt) % mod;
        long long right = dfs(rt) % mod;

        int left_nums = lt.size(), right_num = rt.size();

        //Ans = No. of ways(Left) * No. of Ways(Right) * (Left)C(n-1)
        //                      OR
        //Ans = No. of ways(Left) * No. of Ways(Right) * (Right)C(n-1)
        return (((table[n-1][left_nums] * left)%mod) * right)%mod;
    }

    int numOfWays(vector<int>& nums) {

        int n = nums.size();

        table.resize(n+1);
        //Compute all possible values of nCr and store them in a table;
        for(int i=0;i<=n;i++){
            table[i] = vector<long long>(i+1, 1);
            for(int j=1;j<i;j++){
                // nCr = (n-1)Cr + (n-1)C(r-1)
                table[i][j] = (table[i-1][j] + table[i-1][j-1])%mod; 
            }
        }

        long long ans = dfs(nums);
        return (ans%mod - 1)%mod;
    
    }

};