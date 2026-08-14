class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0, right = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            right++;

            freq[s[i]]++;

            while (freq[s[i]] > 2) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left);
        }

        return ans;
    }
};