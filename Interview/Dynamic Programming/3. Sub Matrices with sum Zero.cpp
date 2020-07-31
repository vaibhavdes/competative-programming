    /*
    
    Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output
2

Explanation
-8 5 7
3 7 -8
5 -8 9

-8 5 7
3 7 -8
5 -8 9
    
    */
    
    public int solve(int[][] A){
        if(A.length==0){
            return 0;
        }
        int []rowSum = new int[A.length];
        int count = 0;
        for(int l=0; l<A[0].length; l++){
            rowSum = new int[A.length];
            for(int r=l; r<A[0].length; r++){
                for(int i=0; i<rowSum.length; i++){
                    rowSum[i]+= A[i][r];
                }
                count+=getZeroSumSubMatrices(rowSum);
            }
        }
        return count;
    }
    public int getZeroSumSubMatrices(int []rowSum){
        HashMap<Integer,Integer> map = new HashMap<>();
        int sum = 0;
        int count = 0;
        for(int i=0; i<rowSum.length; i++){
            sum = 0;
            for(int j=i; j<rowSum.length; j++){
                sum+=rowSum[j];
                if(sum==0){
                    count++;
                }
            }
        }
        return count;
    }
