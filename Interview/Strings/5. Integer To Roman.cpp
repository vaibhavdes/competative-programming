/*


Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 


Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
    
    
*/




// SOLUTION 1 
/*
string Solution::intToRoman(int A) {
        string M[] = {"", "M", "MM", "MMM"};                                              // 1000, 2000, 3000
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};        // 100, 200, 300, .. 900
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};        // 10, 20, ... 90
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};        // 1, 2, ... 9
        return M[A/1000] + C[(A%1000)/100] + X[(A%100)/10] + I[A%10];
    }
};
*/


// SOLTUION 2

string Solution::intToRoman(int A) {
    int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};   
    string r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    auto i = 0;
    string result = "";
    while (A!=0)
    {
        while (A>=n[i])
        {
            result += r[i];
            A -= n[i];
        }
        ++i;
    }
    return result;
}
