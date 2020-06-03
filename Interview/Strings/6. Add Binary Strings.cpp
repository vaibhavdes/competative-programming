/*

Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

*/


string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    auto x = A.length(), y = B.length();
    int n = x>=y ? x : y;
    int c = 0;
    string result = "";
    for (auto i = 0; i<n; ++i)
    {
        int a = i < x ? A[i] - '0' : 0;
        int b = i < y ? B[i] - '0' : 0;
        int temp = a + b + c;
        c = temp / 2;
        result += to_string(temp%2);
    }
    if (c==1)
        result += to_string(c);
    reverse(result.begin(), result.end());
    return result;
}
