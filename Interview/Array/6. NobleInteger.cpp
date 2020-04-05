/*

Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

*/


int Solution::solve(vector<int> &A) {
    int size = A.size();
    if(size==0)
        return -1;  
    sort(A.begin(), A.end()) ;
    
      for(int i=0;i<size;i++){
        while(i+1<size && A[i]==A[i+1])
          i++;
        if(A[i]==size-1-i)
          return 1;
      }
      
      return -1;
}
