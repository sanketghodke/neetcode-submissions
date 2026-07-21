class Solution {
public:
    int findMin(vector<int> &nums) {
        // 3 4 5 6 1 2
        int low = 0; 
        int high = nums.size()-1;
        int ans =INT_MAX;
        int mid;
        while(low<=high){
            mid = (low+high)/2;

            if(nums[mid] <= nums[high]){
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
            else{
                ans = min(ans,nums[low]);
                low = mid+1;
            }
        }
        return ans;
    }
};
