class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0, r=0, ans=0;
        unordered_map<char, int> freq;
        while(r<s.size()) {
            freq[s[r]]++;
            while(freq[s[r]]>2) {
                freq[s[l]]--;
                l++;
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};