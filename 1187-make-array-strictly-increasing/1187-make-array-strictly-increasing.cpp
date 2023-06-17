class Solution {
public:
    map<pair<int,int>,int>dp;
    int fun(vector<int>&v , vector<int>&v2 , int i , int pre ){
        if(i>=v.size()){
            return 0 ;
        }

        if(dp.find({i,pre}) != dp.end()){
            return dp[{i,pre}];
        }

        int ans = 2001;
        auto it = upper_bound(v2.begin() , v2.end() , pre);
        
        if(v[i]> pre){
            ans = min(ans ,fun(v,v2,i+1,v[i]));
            if(it!=v2.end() && *it>pre){
                ans = min(ans , 1 + fun(v,v2,i+1 , *it ));
            }
        }
        else{
            if(it != v2.end() && *it>pre ){
                ans = 1 + fun(v,v2,i+1,*it);
            }
        }

        return dp[{i,pre}] = ans ;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin() , arr2.end());
        int ans = INT_MAX ;
        ans = min(ans , fun(arr1,arr2,0,INT_MIN));
        return ans>=2001?-1:ans;
    }
};