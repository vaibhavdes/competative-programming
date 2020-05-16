/*
Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

Note: INT_MAX = 2^31 - 1

*/

public int divide(int A, int B) {
        if(A == Integer.MIN_VALUE && B == -1)return Integer.MAX_VALUE;
        int ans = 0;
        int check = 1;
        if(A<0)check*=-1;
        if(B<0)check*=-1;
        A = Math.abs(A);
        B = Math.abs(B);
        while(A-B>=0){
            A-=B;
            ans++;
        }
        return ans*check;
    }
