/*

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4


A = is repeated Number
B = is missing Number
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    long long int sum = (len * (len + 1)) / 2;
    long long int sumN = (len * (len + 1) * (2 * len + 1))/6;
    long long int missing = 0;
    long long int repeated = 0;
    vector <int> ans;
    
    for(int i = 0; i < A.size(); i++){
        sum -= (long long int)A[i];
        sumN -= (long long int)A[i]*(long long int)A[i];
    }
    
    missing = (sum + sumN/sum)/2;
    repeated = missing - sum;
 
    ans.push_back(repeated);
    ans.push_back(missing);
    return ans;
}
