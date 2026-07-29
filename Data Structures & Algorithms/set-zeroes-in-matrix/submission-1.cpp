class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // traverse and mark all col and row heads

        int n = matrix.size();
        int m = matrix[0].size();
        int col0=1;

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(matrix[i][j] == 0){
                    if(j == 0) {col0 = 0;}
                    else{
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }

        // NOW very important that you travel reverse-- because if you do normal traversal
        // it will update row where you are storing all 0, and it will affect all matrix

        for(int i = n-1; i>0; i--){
            for(int j = m-1; j>0; j--){
                if(matrix[0][j] == 0 || matrix[i][0] ==0){
                    matrix[i][j] = 0;
                }
            }
        }

        // now you must do the row first -- because first row contains columns
        if(matrix[0][0] == 0){
            for(int i = 0; i<m ; i++){
                matrix[0][i] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i<n ; i++){
                matrix[i][0] = 0;
            }
        }

    }
};
