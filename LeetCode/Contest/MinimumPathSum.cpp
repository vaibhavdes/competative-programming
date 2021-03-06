
/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i=0; i<r; i++){
            for(int j=0;j<c; j++){
                if(i == 0 && j == 0)
                    continue;
                
                if(i==0)
                    grid[i][j] = grid[i][j] + grid[i][j-1];
                else if(j==0)
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                else 
                    grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
               
            }
        }
        return grid[r-1][c-1];
    }
};
