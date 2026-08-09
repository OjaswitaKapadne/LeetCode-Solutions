class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int count=0, bouquets=0;
        int n=bloomDay.size();
        for(int i=0; i<n; i++) {
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
        int n=bloomDay.size();
        if((long long)m*k > n) {
            return -1;
        }
        int maxx=*max_element(bloomDay.begin(), bloomDay.end());
        int low=0, high=maxx;
        int ans=high;
        while(low<=high) {
            int mid=(high-low)/2+low;
            if(isPossible(bloomDay, m, k, mid)) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};