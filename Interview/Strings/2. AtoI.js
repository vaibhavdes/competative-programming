/*

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions: 
Q1. Does string contain whitespace characters before the number?
A. Yes 
Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. 
Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. 
Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 

*/


//JS
 atoi : function(A){
        A = A.trim();
        if (A.length < 1) return 0;
        
        var isNegative = A[0] === '-';
        var startsFromPlus = A[0] === '+';
        if ((isNegative || startsFromPlus) && A.length < 2) return 0;

        var res = 0;
        var i = (isNegative || startsFromPlus) ? 1 : 0;
        var MAX_INTEGER = Math.pow(2, 31) - 1;
        var MIN_INTEGER = -Math.pow(2, 31);
        
        while (/[0-9]/.test(A[i])) {
            if (MAX_INTEGER / 10 - Number(A[i]) < res) {
                return isNegative ? MIN_INTEGER : MAX_INTEGER;
            }
            
            res = res * 10 + Number(A[i]);
            i++;
        } 
        
        return isNegative ? -1 * res : res;
}


// CPP

int Solution::atoi(const string A) {
    int sign = 1, base = 0, i = 0;
    while (A[i] == ' ') { i++; }
    if (A[i] == '-' || A[i] == '+') {
        sign = (A[i++] == '-') ? -1 : 1; 
    }
    while (A[i] >= '0' && A[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && A[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (A[i++] - '0');
    }
    return base * sign;

}
