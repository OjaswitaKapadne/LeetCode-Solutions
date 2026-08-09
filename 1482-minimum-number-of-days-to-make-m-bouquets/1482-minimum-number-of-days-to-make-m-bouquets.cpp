class Solution {
public:
    bool calculate(vector<int>& bloomDay, int m, int k, int day) {
        int count=0, bouquets=0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i]<=day) {
                count++;
            } else {
                bouquets+=(count/k);
                count=0;
            }
        }
        bouquets+=(count/k);
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) {
            return -1;
        }
        int maxx = *max_element(bloomDay.begin(), bloomDay.end());
        int low=1, high=maxx;
        int ans=maxx;
        while(low<=high) {
            
            int mid=(high-low)/2 + low;
            if(calculate(bloomDay, m, k, mid)) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};