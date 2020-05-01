/*

Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
        
 */
        
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> v(A,vector<int>(A,0));
    int l = 0;
    int r = A - 1;
    int t = 0;
    int b = A - 1;
    int count = 1;
    while(t<=b && l<=r) {
        for(int i = l; i<=r ; i++) {
            v[t][i] = count;
            count++;
        }
        t++;
        for(int i=t; i<=b ; i++) {
            v[i][r] = count;
            count++;
        }
        r--;
        for(int i =r; i>=l; i--) {
            v[b][i] =count;
            count ++;
        }
        b--;
        for(int  i=b; i>=t; i--) {
            v[i][l] = count;
            count++;
        }
        l++;
    }
    return v;
}
