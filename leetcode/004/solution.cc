class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        return (findKth(nums1, nums2, (n1 + n2 + 1) >> 1) + 
                findKth(nums1, nums2, (n1 + n2 + 2) >> 1)) / 2.0;
    }
    
private:
    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 == 0) return nums2[k - 1];
        if(n2 == 0) return nums1[k - 1];
        if(k == 1) return min(nums1[0], nums2[0]);
        int mid1 = min(n1, k / 2), mid2 = min(n2, k / 2);
        if(nums1[mid1 - 1] <= nums2[mid2 - 1]) 
            return findKth(vector<int> (nums1.begin() + mid1, nums1.end()), nums2, k - mid1);
        else 
            return findKth(nums1, vector<int> (nums2.begin() + mid2, nums2.end()), k - mid2);
    }
};
