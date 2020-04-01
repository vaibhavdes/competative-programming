
/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
    
Input :
Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.
Output :

Return an Integer, i.e minimum number of steps.
Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2

 */
 
 public class Solution {
    public int coverPoints(int[] A, int[] B) {
        int steps = 0;
        for(int i = 0; i < A.length-1; i++)
        {
            steps += path(A[i],A[i+1],B[i],B[i+1]);
        }
        return steps;
    }
    public int path(int A,int AA, int B, int BB)
    {
        int x = Math.abs(A - AA);
        int y = Math.abs(B - BB);
        return Math.max(x,y);
    }
}
