//https://leetcode.com/problems/toeplitz-matrix/description/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        for(int j=0;j<m;j++){
            int target = matrix[0][j];
            int row = 1,col = j+1;
            bool f = true;
            while(row<n && col<m){
                if(matrix[row][col] != target)
                f=false;
                row++;
                col++;
            }
            if(!f) return false;
        }
        for(int i=1;i<n;i++){
            int target = matrix[i][0];
            int row = i+1,col = 1;
            bool f = true;
            while(row<n && col<m){
                if(matrix[row][col] != target)
                f=false;
                row++;
                col++;
            }
            if(!f) return false;
        }
        return true;
    }
};