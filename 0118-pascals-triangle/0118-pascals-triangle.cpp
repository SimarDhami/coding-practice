class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int row=1;row<=numRows;row++){
            vector<int>temp;
            long long ans=1;
            temp.push_back(ans);
            for(int col=1;col<row;col++){
                ans=ans*(row-col);
                ans=ans/col;
                temp.push_back(ans);
            }
            res.push_back(temp);
        }
        return res;
    }
};