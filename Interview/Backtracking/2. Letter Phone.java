/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

IMAGE [Consider: Landline DialPad with letter associated with each key]

The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

*/


 String[] map = new String[] {
                                   "0", 
                                   "1", 
                                   "abc", 
                                   "def", 
                                   "ghi", 
                                   "jkl", 
                                   "mno",
                                   "pqrs", 
                                   "tuv", 
                                   "wxyz"
                              };
        
        
    public ArrayList<String> letterCombinations(String A) {
        ArrayList<String> ans = new ArrayList<String>();        
        backtrack(A,ans,"",0);
        return ans;
    }
    
    public void backtrack(String A, ArrayList<String> ans, String str, int index){
        if(index>=A.length()){
            ans.add(str);
            return;
        }
        int idx = (int)(A.charAt(index)-'0');
        String temp = map[idx]; 
        for(int j=0;j<temp.length();j++){
            backtrack(A,ans,str+temp.charAt(j),index+1);
        }
    }
