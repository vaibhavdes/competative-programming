/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/


class Solution {
    public int numIslands(char[][] grid) {
        if(grid.length == 0)
            return 0;
    
        int rows = grid.length;
        int cols = grid[0].length;
        int islands = 0;
        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if(grid[i][j]=='1'){
                    islands += dfs(grid,i,j);                    
                }
            }
        }
        
        return islands;
    }
    
    public int dfs(char[][] grid, int row, int col) {
        if(row < 0 || row >= grid.length ||  col < 0  || col >= grid[row].length || grid[row][col] == '0')
            return 0;
        
        grid[row][col] = '0';
        
        dfs(grid,row+1,col);        // DOWN
        dfs(grid,row-1,col);        // UP
        dfs(grid,row, col+1);       // RIGHT
        dfs(grid,row, col-1);       // LEFT
        
        return 1;
    }
}
