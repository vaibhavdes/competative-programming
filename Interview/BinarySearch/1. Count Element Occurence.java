/*

Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.


*/

public class Solution {
	public int findCount(final List<Integer> a, int b) 
	{
	    int first=binarySearch(a,b,true);
	    if(first==-1)
	        return 0;
	    else
	        return binarySearch(a,b,false)-first+1;
	        
	}
	public int binarySearch(List<Integer> a, int b, Boolean first)
	{
	    int low=0,high=a.size()-1,result =-1;
	    while(low<=high)
	    {
	        int mid=(low+high)/2;
	        if(a.get(mid)==b)
	        {
	            result=mid;
	            if(first)
	                high=mid-1;	 
	            else
	                low=mid+1;
	        }
	        else if(a.get(mid)>b)
	            high=mid-1;
	        else
	            low=mid+1;
	    }
	    return result;
	}
}
