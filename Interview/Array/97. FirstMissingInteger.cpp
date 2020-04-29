/*

Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space

*/



int Solution::firstMissingPositive(vector<int> &A) {
    int size = A.size();
      for (int i = 0; i < size; i++) {
                if (A[i] > 0 && A[i] <= size) {
                    int x = A[i] - 1;
                    if (A[x] != A[i]) {
                        swap(A[x], A[i]);
                        i--;
                    }
                }
            }
            for (int i = 0; i < size; i++) {
                if (A[i] != i + 1) return (i + 1);
            }
            return size + 1;
      }
}

