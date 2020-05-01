/*

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:

    1. If there is a tie, then compare with segment's length and return segment which has maximum length.
    2. If there is still a tie, then return the segment with minimum starting index.


Input Format:

The first and the only argument of input contains an integer array A, of length N.
Output Format:

Return an array of integers, that is a subarray of A that satisfies the given conditions.
Constraints:

1 <= N <= 1e5
1 <= A[i] <= 1e5
Examples:

Input 1:
    A = [1, 2, 5, -7, 2, 3]

Output 1:
    [1, 2, 5]

Explanation 1:
    The two sub-arrays are [1, 2, 5] [2, 3].
    The answer is [1, 2, 5] as its sum is larger than [2, 3].

Input 2:
    A = [10, -1, 2, 3, -4, 100]
    
Output 2:
    [100]

Explanation 2:
    The three sub-arrays are [10], [2, 3], [100].
    The answer is [100] as its sum is larger than the other two.
    
  */


vector<int> Solution::maxset(vector<int> &A) {
   long long int start=0, end=0, ansStart=0, length=0, ansLength=0, ansEnd=-1, sumTillNow = INT_MIN, maxTillNow=INT_MIN;
   int i=0;
   
   while(i<A.size()){
       if(A[i]>=0){
            start = i;
            sumTillNow =0;
            length =0;
            
            while(A[i]>=0 && i<A.size()){
                sumTillNow +=A[i];
                i++;   
            }
            end = i-1;
            
           if( ( sumTillNow>maxTillNow ) || ( sumTillNow==maxTillNow && end - start +1 < ansLength ) ){
               ansStart = start;
               ansEnd = end;
               ansLength = start + end -1 ;
               maxTillNow = sumTillNow;
            }
       }
       i++;
       
    }
       vector <int> ans;
       for(int i=ansStart; i<=ansEnd;i++){
           ans.push_back(A[i]);
       }
       
       return ans;
  
}
