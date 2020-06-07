/*
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 
*/


int Solution::strStr(const string A, const string B) {
    int start=0,temp_start=start,j=0;
    while(temp_start<A.size() && j<B.size())
    {
        if(A[temp_start]==B[j])
        {
            temp_start++,j++;
        }
        else
        {
            j=0,temp_start=++start;
        }
        if(j==B.size()) return start;
    }
    return -1;
}
