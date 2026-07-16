// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         long long product = 1;
//         sort
//         for(int i =0; i<nums.size(); i++){
//             product *= nums[i];
//         }
//         vector<int> ans;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] ==0) 
//             {
//                 ans.push_back(product);
//                 continue;
//             } 
//             ans.push_back(product/nums[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size(),1);
        vector<int> suff(nums.size(),1);
        int prod = 1;
        // 1 1 2 8
        for(int i = 1; i<nums.size(); i++){
            pref[i] = nums[i-1]*prod;
            prod = prod * nums[i-1];
        }
        int prod2 = 1;
        // 48 24 6 1
        for(int i=nums.size()-2; i>=0; i--){
            suff[i] = nums[i+1]*prod2;
            prod2 = prod2 * nums[i+1];
        }
        vector<int>ans(nums.size());
        for(int i = 0; i<nums.size(); i++){
            ans[i] = pref[i]* suff[i];
        }
        return ans;
    }
};

// 1 1 2 8


// 6 1
