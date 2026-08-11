class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        if (s1.size() > s2.size()) return false;

        for (char c : s1) {
            freq1[c - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            freq2[s2[i] - 'a']++;
        }
        if (freq1 == freq2) return true;
        int k = s1.size();
        for (int i = k; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;          // Add new character
            freq2[s2[i - k] - 'a']--;      // Remove old character

            if (freq1 == freq2)
                return true;
        }
        return false;

    }
};
