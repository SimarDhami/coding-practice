class Solution {
public:

int left(vector<int>& nums, int target){
    int low=0;
        int high=nums.size()-1;
        int res=-1;
        int mid;
        while(high>=low){
            mid=(low+high)>>1;
            if(nums[mid]>target)
            high=mid-1;
            else if(nums[mid]<target)
            low=mid+1;
            else{
                res=mid;
                high=mid-1;

            }
        }
        return res;
}
int right(vector<int>& nums, int target){
    int low=0;
        int high=nums.size()-1;
        int res=-1;
        int mid;
        while(high>=low){
            mid=(low+high)>>1;
            if(nums[mid]>target)
            high=mid-1;
            else if(nums[mid]<target)
            low=mid+1;
            else{
                res=mid;
                low=mid+1;

            }
        }
        return res;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int low=left(nums,target);
    int high=right(nums,target);
    return vector<int>({low,high});
    }
};
