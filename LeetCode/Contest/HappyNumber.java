/*
 Those numbers for which this process ends in 1 are happy numbers.
 
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

class Solution {
    public boolean isHappy(int n) {
        if(n==1)
            return true;
        else {
            
            int slow = n;
            int fast = squareSum(n);
            
            while(fast != 1 && slow != fast) {
                slow = squareSum(slow);
                fast = squareSum(squareSum(fast));
                        
            }
            return fast == 1;
        }
    }
    
    private int squareSum(int num){
        int sum = 0;

        while(num > 0){
            sum += Math.pow(num%10,2);
            num /= 10;
        }
        
        return sum;
    }
}
