class Solution {
public:
    int sumD(vector<int>& nums, int val) {
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=ceil((double)nums[i]/ double(val));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        int ans=high;

        while(low<=high) {
            int mid = (high-low)/2 + low;
            if((sumD(nums, mid))<=threshold) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};