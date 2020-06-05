/*

Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

*/


string revv(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}

string Solution::longestPalindrome(string A) {
  int n = A.length();
  if (n == 0) return "";
  string longest = A.substr(0, 1);  
  for (int i = 0; i < n-1; i++) {
    string p1 = revv(A, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = revv(A, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}
