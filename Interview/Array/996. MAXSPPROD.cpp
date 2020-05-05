/*


You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j.

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9


*/

int Solution::maxSpecialProduct(vector<int> &A) {
    long long int l=0;
    long long int r=0;
    long long int ans=0;
    int beg=0;
    int end=0;
    int flag=0;
    for(int end=1;end<A.size()-1;end++){
        if(A[beg]>A[end]){
            l=beg;
            flag=1;
        }
        if(A[end-1]>A[end]){
            beg=end-1;
            l=beg;
            flag=1;
        }
        if(flag==0){
            beg=beg+1;
        }
        if(A[end+1]>A[end]){
            r=end+1;
        }
        if(l*r>ans){
            ans=l*r;
        }
        l=0;
        r=0;
        flag=0;
    }
    return (int) (ans % 1000000007);
}

