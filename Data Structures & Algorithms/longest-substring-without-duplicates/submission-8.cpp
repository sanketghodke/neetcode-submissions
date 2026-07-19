class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        // character and index above.
        
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (mpp.count(s[right])) {
                left = max(left, mpp[s[right]] + 1);
            }

            mpp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};