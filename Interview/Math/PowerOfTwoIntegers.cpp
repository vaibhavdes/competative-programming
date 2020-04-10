/*

Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

*/


int Solution::isPower(int A) {
    if(A < 2)
        return 1;
    int P = 2;
    float p = pow(A,1.0/P);
    while((int)p>1){
        if(p-(int)p==0)
            return 1;
        P++;
        p=pow(A,1.0/P);
    }
    return 0;
}
