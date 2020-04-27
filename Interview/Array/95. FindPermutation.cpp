/*

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

1. Length of given string s will always equal to n - 1
2. Your solution should run in linear time and space.

Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

*/

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans;
    int low = 1;
    int high = B;
    
    for(int i=0; i< A.size(); i++) {
        if(A[i] == 'I') {
            ans.push_back(low);
            low++;
        }
        else if(A[i] == 'D') {
            ans.push_back(high);
            high--;
        }
    }
    ans.push_back(low);
    return ans;
}
