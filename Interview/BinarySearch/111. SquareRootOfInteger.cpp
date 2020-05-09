/*

Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))
Constraints

1 <= A <= 10^9
For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3
    
 */
 
 class Solution {
    public:
        int sqrt(int x) {
            if (x == 0) return 0;
            int start = 1, end = x, ans;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (mid <= x / mid) {
                    start = mid + 1;
                    ans = mid;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
        }
};



/*

int squareRoot(int A, int low, int high) {

    int mid = floor(low + (high - low) / 2);
    if(low<=high) {
        if(mid <= (A/mid) && (mid+1) > (A/(mid+1))){
            return mid;
        }
        else if(mid < (A/mid)) {
            low = mid + 1;
            return squareRoot(A,mid+1,high);
        }
        else if(mid > (A/mid)) {
            high = mid -1;
            return squareRoot(A, low, high);
        }
    }
    return mid;
}

int Solution::sqrt(int A) {
    if(A==0)
        return 0;
    else if (A==1)
        return 1;
    else
        return squareRoot(A,0,A);

}


*/
