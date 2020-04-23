/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations.
Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' : 
aab
aba
baa
The answer might not fit in an integer, so return your answer % 1000003

 NOTE: 1000003 is a prime number
NOTE: Assume the number of characters in string < 1000003 

*/

import java.math.BigInteger;
public class Solution {
    public int findRank(String A) {
        BigInteger rank = BigInteger.ONE;
        BigInteger permCount = BigInteger.ONE;
        Map<Character, Integer> chars = new HashMap<Character,Integer>();
        
        for(int i = A.length() - 1; i > -1; i--) {
            char x = A.charAt(i);
            int count = chars.containsKey(x) ? chars.get(x) + 1 : 1;
            chars.put(x, count);
            for(Map.Entry<Character,Integer> e: chars.entrySet()) {
                if(e.getKey() < x) {
                    rank = rank.add((permCount.multiply(BigInteger.valueOf(e.getValue()))).divide(BigInteger.valueOf(count)));
                }
            }
            permCount = permCount.multiply(BigInteger.valueOf(A.length() - i)).divide(BigInteger.valueOf(count));
        }
        return rank.remainder(BigInteger.valueOf(1000003)).intValue();
    }
}
