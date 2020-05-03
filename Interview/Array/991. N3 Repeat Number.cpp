/*

You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

*/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int size = A.size();
    if(size == 0)
        return -1;
    if(size == 1) 
        return A[0];
        
    int a = A[0];
    int b = A[1];
    int c1 = 0;
    int c2 = 0;
    
    for(int num : A) {
        if( a == num) {
            c1++;
        }
        else if(b == num) {
            c2++;
        }
        else if(c1 == 0) {
            a = num;
            c1 = 1;
        }
        else if(c2 == 0) {
            b = num;
            c2 = 1;
        }
        else {
            c1--;
            c2--;
        }
    }
    
    c1 = 0;
    c2 = 0;
    
    for(int num : A) {
        if(a == num) {
            c1++;
        }
        else if(b == num) {
            c2++;
        }
    }
    
    if(c1 > size/3) {
        return a;
    }
    else if(c2 > size/3) {
        return b;
    }
    else {
        return -1;
    }
}
