/*

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

*/


public class Solution {
    public ArrayList<Integer> plusOne(ArrayList<Integer> A) {
        int size = A.size();
        int extra = 1;
        int temp = 0;
        if(size!=0)
        {
            while(extra!=0)
            {
                temp = A.get(size-1) + extra;
                if(temp>9)
                    A.set(size-1,(A.get(size)%10));
                    
                extra = extra/10;
                size--;
            }
        }
        if(extra!=0)
            A.add(extra);

        return A;
    }
}
