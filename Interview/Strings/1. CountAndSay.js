/*The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

*/

 
  countAndSay : function(A){
    var count;
    var start = "1";

    for (var i = 1; i < A; ++i) {

      var temp = "";
      count = 1; 
      for (var j = 0; j < start.length; ++j) {

        if (start.charAt(j) === start.charAt(j + 1)) 
          count++;
        else {
          temp += count + start.charAt(j);  
          count = 1;
        }

      }

      start = temp; 
    }

    return start;
  }

