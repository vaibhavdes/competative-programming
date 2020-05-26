/*

Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]


*/


void Solution::merge(vector<int> &A, vector<int> &B)
{

    int i = A.size() - 1; 
    int j = B.size() - 1; 
    
    int lastPos = A.size() + B.size() - 1; 
    
    A.resize(A.size() + B.size());
    
    while(j >= 0)
    {
        if(i >= 0 and A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }
    
}





/*

void Solution::merge(vector<int> &A, vector<int> &B) {
  vector<int> ans;
    int i=0,j=0;
    int m = A.size(),n=B.size();

    while(i<m && j<n){

        if(A[i]<B[j]){
            ans.push_back(A[i]);
            i++;
        }
        else if(A[i]>B[j]){
            ans.push_back(B[j]);
            j++;
        }
        else{
            ans.push_back(A[i]);
            ans.push_back(B[j]);
            i++;
            j++;
        }
    }
    while(i<m){
        ans.push_back(A[i]);
        i++;
    }
    while(j<n){
        ans.push_back(B[j]);
        j++;
    }
    A=ans;
}


*/
