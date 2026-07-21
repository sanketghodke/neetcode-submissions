class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 00 01 02
        // 10 11 12
        // 20 21 22

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = n*m - 1; 
        while(low<=high){
            int mid = (low+high)/2;

            int nrow = mid/n;
            int ncol = mid%n;

            if(matrix[nrow][ncol] == target){
                return true;
            }
            else if(target < matrix[nrow][ncol]  ){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return false;

    }
};
