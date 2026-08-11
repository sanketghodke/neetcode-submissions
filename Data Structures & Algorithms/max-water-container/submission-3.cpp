class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxWater = INT_MIN;
        while(left < right){
            maxWater = max(maxWater, (right-left)*min(heights[left],heights[right]));

            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};
