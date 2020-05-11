/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0


*/


int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    
    int size = A.size();
    int low = 0; 
    int high = size-1;
    int mid = low + (high - low) /2;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(A[mid] == B || (mid ==0 && B<A[mid]) || (mid > 0 && B < A[mid] && B>A[mid-1]))
            return mid;
        if(B>A[mid])
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return size;
    
}
