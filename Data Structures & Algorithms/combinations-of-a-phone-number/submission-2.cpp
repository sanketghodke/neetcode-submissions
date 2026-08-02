class Solution {
public:
    vector<string> digitToChar = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void recc(int ind, string& temp, vector<string>& ans, string& digits) {

        if (ind == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = digitToChar[digits[ind] - '0'];

        // Instead of take/not take,
        // we try every possible character.
        for (char ch : letters) {
            temp.push_back(ch);
            recc(ind + 1, temp, ans, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        string temp = "";

        if (digits.empty())
            return ans;

        recc(0, temp, ans, digits);

        return ans;
    }
};