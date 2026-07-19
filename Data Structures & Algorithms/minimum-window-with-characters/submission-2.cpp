class Solution {
   public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int start = -1;
        int minL = INT_MAX;
        int m = s.size();
        int n = t.size();
        int count = 0;

        vector<int> mpp(256, 0);

        for (int i = 0; i < n; i++) {
            mpp[t[i]]++;
        }

        while (right < m) {
            if (mpp[s[right]] > 0) count++;

            mpp[s[right]]--;

            while (count == n) {
                if (right - left + 1 < minL) {
                    minL = right - left + 1;
                    start = left;
                }

                mpp[s[left]]++;

                if (mpp[s[left]] > 0) count--;

                left++;
            }

            right++;
        }
        if(start == -1){
            return "";
        }
        else{
            return s.substr(start,minL);
        }
    }
};
