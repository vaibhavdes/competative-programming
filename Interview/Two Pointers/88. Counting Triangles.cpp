/*


You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4

*/


int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int n=A.size(),count=0;
    long long int m = pow(10, 9);
    for(int i=0;i<n-2;i++){
        if(A[i]==0) continue;
        for(int j=i+1;j<n-1;j++)
            count=(count+((lower_bound(A.begin(),A.end(),A[i]+A[j]))-(A.begin()+j+1)))%m;
    }
    return count;
}
