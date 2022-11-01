//https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n, -1));
        for (int j = 0; j < n; j++) dp[m][j] = j; //Initializing the answer to the bottom case subproblem
        //===================================================
        for (int i = m - 1; i >= 0; i--) //Move from bottom to top,                        
        {                               //as subproblems of next row should be solved before current row
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) //if board is right
                {
                    bool isRightCellRight = (j + 1 == n)? false : (grid[i][j + 1] == 1);
                    if (isRightCellRight) dp[i][j] = dp[i + 1][j + 1]; 
                    //if we can reach next row, take the answer from the next row subproblem
                }
                else if (grid[i][j] == -1) //if board is left
                {
                    bool isLeftCellLeft = (j - 1 < 0)? false : (grid[i][j - 1] == -1);
                    if (isLeftCellLeft) dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
        //=============================================================
        return dp[0];
        
    }
};

class Solution {
public:
 int dp[105][105];
 int n,m;
  bool isValid(int i,int j){
      return (i>=0 && j<m && i<n && j>=0);
  }
  int result(int i,int j,vector<vector<int>>grid){
      if(i == n)
      return j;
      if(isValid(i,j)){
          if(grid[i][j] == 1 && isValid(i,j+1) && grid[i][j+1]==1){
              if(dp[i+1][j+1] != -2)
              return dp[i+1][j+1];
              else
              return dp[i+1][j+1] = result(i+1,j+1,grid);
          }
          else if(grid[i][j] == -1 && isValid(i,j-1) && grid[i][j-1] == -1){
              if(dp[i+1][j-1] != -2)
              return dp[i+1][j-1];
              else
               return dp[i+1][j-1] = result(i+1,j-1,grid);
          }
      }
      return -1;
  }
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<=101;i++){
            for(int j=0;j<=101;j++)
            dp[i][j] = -2;
        }
        vector<int>ans(n);
        for(int k=0;k<n;k++){
           ans[k] = result(0,k,grid);
        }
        return ans;
    }
};
