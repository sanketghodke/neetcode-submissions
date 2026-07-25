class Solution {
   public:
    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void recc(int index, vector<vector<string>>& ans, vector<string>& path, string s) {
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPali(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                recc(i+1, ans, path,s);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        recc(0, ans, path, s);
        return ans;
    }
};
