/*

Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1

*/

import java.math.BigInteger;

public class Solution {
    public int power(String A) {
        if(A.equals("1")){
			return 0;
		}
		BigInteger b = new BigInteger(A);
		while((b.and(BigInteger.ONE).compareTo(BigInteger.ZERO)==0 && b.compareTo(BigInteger.ONE)>0)){
			b=b.shiftRight(1);
		}
		if(b.compareTo(BigInteger.ONE)==0){
			return 1;
		}
		else{
			return 0;
		}
    }
}
