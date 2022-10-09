class Solution {
public:
    int maxSum(vector<vector<int>>& mat) {
        int R=mat.size(); //row
        int C=mat[0].size(); //col
         if (R<3 || C<3) {
          exit(0);
        }
        int max_sum = INT_MIN;
        for (int i=0; i<R-2; i++) {
            for (int j=0; j<C-2; j++) {
                int sum = (mat[i][j]+mat[i][j+1]+mat[i][j+2])+ 
                              (mat[i+1][j+1])+
                        (mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2]);
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
    }
};
