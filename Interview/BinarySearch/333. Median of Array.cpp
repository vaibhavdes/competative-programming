/*


There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output
3

NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 



*/


double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    if(A.size()>B.size())return findMedianSortedArrays(B,A);
    
    int x = A.size();
    int y = B.size();
    
    int low =0;
    int high = x;
    
    while(low<=high)
    {
        int partX = (low+high)/2;
        int partY = (x+y+1)/2-partX;
        
        int maxleftX = (partX==0)?INT_MIN:A[partX-1];
        int minrightX = (partX==x)?INT_MAX:A[partX];
        
        int maxleftY = (partY==0)?INT_MIN:B[partY-1];
        int minrightY = (partY==y)?INT_MAX:B[partY];
        
        
        if(maxleftX<=minrightY && maxleftY<=minrightX)
        {
            if((x+y)%2==0)
                return  (double)(max(maxleftX,maxleftY)+min(minrightX,minrightY))/2;
            else
                return (double)(max(maxleftX,maxleftY));
        }
        else if(maxleftX>minrightY)
        {
            high = partX-1;
        }
        else if(maxleftY>minrightX)
        {
            low = partX+1;
        }
    }
}
