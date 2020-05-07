/*

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.


Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
*/

void Solution::setZeroes(vector<vector<int> > &A) {
   int k=0;
   int r=0;
   for(int i=0;i<A.size();i++){
       if(A[i][0]==0){
           k=1;
           break;
       }
   }
   for(int j=0;j<A[0].size();j++){
       if(A[0][j]==0){
           r=1;
           break;
       }
   }
   
   for(int i=1;i<A.size();i++){
       for(int j=1;j<A[0].size();j++){
           if(A[i][j]==0)
           {
               A[i][0]=0;
               break;
           }
       }
   }
   for(int j=1;j<A[0].size();j++){
       for(int i=1;i<A.size();i++){
           if(A[i][j]==0){
               A[0][j]=0;
               break;
           }
       }
   }
   for(int i=1;i<A.size();i++){
       for(int j=1;j<A[0].size();j++){
           if(A[0][j]==0||A[i][0]==0){
               A[i][j]=0;
           }
       }
   }
   if(k==1){
       for(int i=0;i<A.size();i++){
            A[i][0]=0;
        }
    }
    if(r==1){
        for(int j=0;j<A[0].size();j++){
            A[0][j]=0;
        }
    }
}



/*
// JAVA

public class Solution {
	public void setZeroes(ArrayList<ArrayList<Integer>> a) {
	    boolean firstRowZero = false;
        boolean firstColumnZero = false;
 
        //set first row and column zero or not
        for(int i=0; i<a.size(); i++){
            if(a.get(i).get(0) == 0){
                firstColumnZero = true;
                break;
            }
        }
 
        for(int i=0; i<a.get(0).size(); i++){
            if(a.get(0).get(i) == 0){
                firstRowZero = true;
                break;
            }
        }
 
        //mark zeros on first row and column
        for(int i=1; i<a.size(); i++){
            for(int j=1; j<a.get(0).size(); j++){
                if(a.get(i).get(j) == 0) {
                    a.get(i).set(0, 0);
                    a.get(0).set(j, 0);
                }
            }
        }
 
        //use mark to set elements
        for(int i=1; i<a.size(); i++){
            for(int j=1; j<a.get(0).size(); j++){
                if(a.get(i).get(0) == 0 || a.get(0).get(j) == 0){
                  a.get(i).set(j, 0);
                }
            }
        }
 
        //set first column and row
        if(firstColumnZero){
            for(int i=0; i<a.size(); i++)
               a.get(i).set(0, 0);
        }
 
        if(firstRowZero){
            for(int i=0; i<a.get(0).size(); i++)
                a.get(0).set(i, 0);
        }
 
	}
}


*/
