class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        //int,index

        for(int i=0; i<nums.size(); i++){
            int res = target - nums[i];

            if(mpp.find(res)!= mpp.end()){
                return {mpp[res], i};
            }
            mpp[nums[i]]=i;
        }
        return{-1,-1};
    }
};
