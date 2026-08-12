class Solution {
public:
    int findKthPositive(vector<int>& arr, int n) {
        int count = 0;
        int k = 1;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == k) {
                k++;
            }
            else {
                count++;

                if(count == n) {
                    return k;
                }

                k++;
                i--;
            }
        }

        return k + (n - count) - 1;
    }
};