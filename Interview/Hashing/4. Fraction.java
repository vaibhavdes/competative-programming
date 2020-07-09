/*

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"


*/



public String fractionToDecimal(int numerator, int denominator) {
      long a=numerator,b=denominator;
      
      if(a%b==0) 
        return String.valueOf(a/b);
      
      Map<Long,Integer> map=new HashMap<>();
      StringBuilder res=new StringBuilder();
      
      if((a>0&&b<0)||(a<0&&b>0))
        res.append("-");
        
      a=Math.abs(a);
      b=Math.abs(b);
      res.append(a/b+".");
      a=(a%b)*10;
      
      while(!map.containsKey(a)){
          map.put(a,res.length());
          res.append(String.valueOf(a/b));
          a=(a%b)*10;
          if(a==0) return res.toString();
      }
      
      return res.insert(map.get(a),"(").append(")").toString();
}
