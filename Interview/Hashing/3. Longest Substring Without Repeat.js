/*

Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/


lengthOfLongestSubstring : function(A){
       var a=A.length,
           ans="",mid="",
           myHash={},
           len=0;
           
        for(var i=0;i<a;i++){
            mid="";
            len=0;
            mid=mid+A[i];len=len+1;
            for(var j=i+1;j<a;j++){
               if(mid.indexOf(A[j])==-1){
                mid=mid+A[j];len=len+1;
               }else{
                break;
               } 
            }
            if(ans.length<mid.length){
                    ans=mid;
            }
        }
    return ans.length;       
}
