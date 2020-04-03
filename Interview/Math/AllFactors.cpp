/*

Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.

*/

vector<int> Solution::allFactors(int A) {
    vector<int> factors;
    for(int i = 1; i<= sqrt(A); i++)
    {
        if(A%i==0) {
            factors.emplace_back(i);
            if(i!=sqrt(A))
                factors.emplace_back(A/i);
        }
                
    }
    sort(factors.begin(),factors.end());
    return factors;
}
