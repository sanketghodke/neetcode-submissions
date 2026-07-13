class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        // integer and count
        for(auto it: nums){
            if(st.count(it)){
                return true;
            }
            else{
                st.insert(it);
            }
        }
        return false;

    }
};

// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         unordered_map<int,int> mpp;
//         // integer and count
//         for(auto it: nums){
//             if(mpp[it]){
//                 return true;
//             }
//             else{
//                 mpp[it] = 1;
//             }
//         }
//         return false;

//     }
// };