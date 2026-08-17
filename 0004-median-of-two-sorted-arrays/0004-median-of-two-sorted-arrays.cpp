class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=nums1.size()-1, j=nums2.size()-1, idx=nums1.size()+nums2.size()-1;
        vector<int>ans(nums1.size()+nums2.size());
        while(i>=0 && j>=0) {
            if(nums1[i]>nums2[j]) {
                ans[idx]=nums1[i];
                idx--;
                i--;
            } else {
                ans[idx]=nums2[j];
                idx--;
                j--;
            }
        }
        while(j>=0) {
            ans[idx]=nums2[j];
            idx--;
            j--;
        }

        while(i>=0) {
            ans[idx] = nums1[i];
            idx--;
            i--;
        }

        int n=ans.size();
        if(n%2!=0) {
            return ans[n/2];
        } else {
            return (ans[n/2]+ans[(n/2)-1])/2.0;
        }
    }
};