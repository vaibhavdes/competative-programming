/*

Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]
 NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output. 

*/




vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int x = 0, y = 0;
    vector<int> result;
    
    while(x<A.size() && y<B.size())
    {
        if(A[x]==B[y])
        {
            result.push_back(A[x]);
            ++x; ++y;
        }
        else if(A[x]<B[y])
            ++x;
        else
            ++y;
    }
    return result;
}
