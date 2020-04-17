/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

public class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
      public class Num implements Comparable<Num> {
            int number;
            public Num(int num){
                this.number = num;
            }
            
            @Override
            public int compareTo(Num num){
                String x = String.valueOf(this.number) + String.valueOf(num.number);
                String y = String.valueOf(num.number) + String.valueOf(this.number);
                return y.compareTo(x);
            }
        }
    public String largestNumber(final int[] A) {
            StringBuffer max = new StringBuffer();
            Num num[];
            int i = 0;
            num = new Num[A.length];
            
            for(int n : A){
                num[i] = new Num(n);
                i++;
            }
            
            Arrays.sort(num);
            for(Num n : num){
                if(n.number == 0 && max.length() != 0)
                    continue;
                max.append(n.number);
            }
            
            return max.toString();
        }
}




/*

// C++ Solution (Not Efficient)

bool customComparator(int a,int b){
    string u = to_string(a);
    string v = to_string(b);
    string w = u + v;
    string x = v + u;
    if(w > x)
        return true;
    
    return false;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> temp  = A;
    
    sort(temp.begin(),temp.end(),customComparator);
    string max = "";
    for(int i=0; i< temp.size(); i++)
        max = max + to_string(temp[i]);
        
    if(max[0] == '0')
        return "0";
    
    return max;
}

*/
