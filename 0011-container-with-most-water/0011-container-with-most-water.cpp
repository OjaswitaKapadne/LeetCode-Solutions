class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxw=0;
        while(l<=r) {
            int ht = min(height[l], height[r]);
            int bd = r-l;
            int area=ht*bd;
            maxw=max(area, maxw);
            if(height[l]>height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return maxw; 
    }
};