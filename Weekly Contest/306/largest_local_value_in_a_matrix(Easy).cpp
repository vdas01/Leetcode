class Solution {
public:
    int result(vector<vector<int>>&grid,int x,int y){
        int maxi = INT_MIN;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                maxi = max(grid[i][j],maxi);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>v(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                v[i][j] = result(grid,i,j);
            }
        }
        return v;
    }
};