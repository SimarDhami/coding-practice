class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i=0; i<nums.size()-2;i++){
            int newTarget = target - nums[i];
            int l= i+1, r = nums.size()-1;
            while(l<r){
                int sum = nums[l]+nums[r];
                diff = abs(diff)>abs(sum-newTarget) ? sum-newTarget : diff;
                if(sum<newTarget)
                    l++;
                else
                    r--;
            }
        }
        return target + diff;
    }
};