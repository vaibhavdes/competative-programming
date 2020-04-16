/*

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

*/
class Solution {
    public boolean checkValidString(String s) {
        if(s.length() == 0)
            return true;
     
        
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c == '(' ) {
                left++;
                right++;
            } else if ( c == ')') {
                if(left > 0)
                   left--;     
                right--;
            } else {
                if(left > 0)
                    left--;
                right++;
            }
            
            if(right < 0)
                return false;
        }
        return left == 0;        
    }
}
