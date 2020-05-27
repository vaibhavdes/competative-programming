
/*

Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.

*/



int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int ans=INT_MAX;
    int i=A.size()-1,j=B.size()-1,k=C.size()-1;
    while(i>=0 and j>=0 and k>=0){
        int max_ele = max(A[i],max(B[j],C[k]));
        int min_ele = min(A[i],min(B[j],C[k]));
        int diff = max_ele - min_ele;
        if(ans>diff)
            ans = diff;
        if(max_ele==A[i])
            i--;
        else if(max_ele==B[j])
            j--;
        else if(max_ele==C[k])
            k--;
    }
    return ans;
}
