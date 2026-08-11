class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // store frequency hash and map with the each string - any
        map<vector<int> , vector<string>> mpp;
        for(auto it: strs){
            vector<int> ch(26,0);
            for(int i =0; i<it.size(); i++){
                ch[it[i] - 'a']++;  
            }
            mpp[ch].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
