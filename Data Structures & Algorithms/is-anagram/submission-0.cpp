// class Solution {
//    public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         if (s.size() != t.size()) {
//             return false;
//         } else {
//             for (int i = 0; i < s.size(); i++) {
//                 if (s[i] != t[i]) return false;
//             }
//         }
//         return true;
//     }
// };


// hashing

class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> ch(26,0);
        for(auto i : s){
            ch[i-'a']++;
        }
        for(auto i : t){
            ch[i-'a']--;
        }
        for(auto it: ch){
            if(it!= 0) return false;
        }
        return true;



    }
};
