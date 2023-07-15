class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1); // As we are going to perform binary search on nums1 and find corresponding elements from nums2 without iterating nums2, it would be great if nums1 is smaller than nums2.
        }
        int low = 0, high = n1; // You are free to take zero elements form nums1 and you can also take complete nums1 array i.e. n1 elements.
        while(low <= high)
        {
            int cut1 = (low + high)/2; // lets make a cut in nums1 and take that many elements from nums1 that comes within that cut. As we know that median will be at the centre, we have to take rest elements from nums2 which will be (n1 + n2)/2 - cut1. Also note that l1 and l2 elements are ending exactly before their cut's index and r1 and r2 pointers are starting exactly from on their cut's index.
            int cut2 = (n1 + n2 + 1)/2 - cut1; // as median will always be at the middle. '+1' is just to balance odd and even sum of n1+n2.
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1]; // Lets say we decide not to take any elements from nums1 therefore we need to initiliaze l1 with INT_MIN to justify the further comparisions.
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1]; // Just in case we chose all elements from nums1 and left nums2 without picking! Therefore we need to do this initilization. 
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            if(l1 <= r2 && l2 <= r1)
            {
                if((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else
                {
                    return max(l1/1.0, l2/1.0);
                }
            }
            else if(l1 > r2)
            {
                high = cut1 - 1; 
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0.0;

    }
};