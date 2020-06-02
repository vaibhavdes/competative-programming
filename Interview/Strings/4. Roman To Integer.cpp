/*

Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at https://en.wikipedia.org/wiki/Roman_numerals#Roman_numeric_system



Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
    
*/






int romanCharToInt(char c)
{
    switch(c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int Solution::romanToInt(string A) {
    int n = A.length();
    int result = 0;
   
    for (int i = 0; i<n; ++i)
    {
        if (i!=n && romanCharToInt(A[i]) < romanCharToInt(A[i+1]))
            result -= romanCharToInt(A[i]);
        else 
            result += romanCharToInt(A[i]);
    }
    return result;
}
