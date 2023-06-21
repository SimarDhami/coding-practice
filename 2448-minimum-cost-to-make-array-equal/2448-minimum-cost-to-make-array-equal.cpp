class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int maxn=nums[0];
        int minn=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxn){
                maxn=nums[i];
            }
            if(nums[i]<minn){
                minn=nums[i];
            }
        }
        // long long mini=0;
        // long long maxi=0;
        // for(int i=0;i<nums.size();i++){
        //     mini+=(abs(nums[i]-minn))*cost[i];
        //     maxi+=abs(nums[i]-maxn)*cost[i];
        // }
        long long i=minn;
        long long j=maxn;
        long long out=LONG_MAX;
        while(i<=j ){
            long long mid=(i+j)/2;
            
            long long curr=0;
            for(int it=0;it<nums.size();it++){
                curr+=abs(nums[it]-mid)*cost[it];
            }
            out=min(curr,out);
            long long curr1=0;
            for(int it=0;it<nums.size();it++){
                curr1+=abs(nums[it]-mid+1)*cost[it];
            }
            long long curr2=0;
            for(int it=0;it<nums.size();it++){
                curr2+=abs(nums[it]-mid-1)*cost[it];
            }
            if(curr<=curr1 && curr<=curr2){
                break;
            }
            else if(curr1<curr2){
                j=mid-1;
                out=curr1;
            }
            else{
                i=mid+1;
                out=curr2;
            }
        }
        return out;
    }
};