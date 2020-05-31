/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/

int Solution::threeSumClosest(vector<int> &A, int B) {
   sort(A.begin(), A.end());														
    int i=0,j=0,k=0;													
    int res=INT_MAX;														
    for(int i=0;i<A.size()-2;i++){											
        j=i+1,k=A.size()-1;													
        while(j<k){														
            int sum=A[i]+A[j]+A[k];											
            if(sum==B) return B;									
            if(sum<B){												
                if(res==INT_MAX) res=sum; 								
                else if((B-sum)<abs(res-B)){						
                    
                    res=sum;											
                } 
                j++;														
            }
            else{
                if(res==INT_MAX) res=sum;
                else if((sum-B)<abs(res-B)){					
                   
                    res=sum;											
                } 
                k--;													
            }
        }
    }
    return res;				
}
