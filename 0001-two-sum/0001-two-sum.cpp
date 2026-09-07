class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int st=0, end=nums.size()-1;
        while(st<end) {
            int sum=nums[st]+nums[end];
            if(sum==target) {
                return {st, end};
                break;
            } else if(target>sum) {
                end--;
            } else {
                st++;
            }
        }
    }
};