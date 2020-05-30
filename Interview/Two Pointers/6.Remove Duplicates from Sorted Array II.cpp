/*

Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

*/


int Solution::removeDuplicates(vector<int> &A) {
  
    int count = 0;
    int n = A.size();
            for (int i = 0; i < n; i++) { 
                if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
                else {
                    A[count] = A[i];
                    count++;
                }
            }
            return count;
}
