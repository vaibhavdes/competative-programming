/*

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1

*/

int num(int i) {
    int x = 1;
    int num = 1;
    while(x <= i){
        num = num * 5;
        x++;
    }
    return num;
}

int Solution::trailingZeroes(int A) {
    int count = 0;
    int i = 1;
    while(num(i) <= A){
        count += (A/num(i));
        i++;
    }
    return count;
}
