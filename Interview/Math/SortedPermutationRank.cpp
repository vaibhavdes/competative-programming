/*

Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003

*/


int factorial(int n) {
    int ans = 1;
    for(int i=1;i<=n; i++) {
        ans = ans * i;
        ans = ans % 1000003;
    }
    return ans;
}

int Solution::findRank(string A) {
    int i = 0;
    int j,c;
    int ans = 0;
    vector<int> R;
    while(A[i]!='\0') {
        j = i;
        c = 0;
        while(A[j]!='\0') {
            if(A[i]>A[j])
                c++;
            j++;
        }
        R.push_back(c);
        i++;
    }
    c = 0;
    i = R.size() -1;
    j = 0;
    while(i >= 0) {
        ans += R[i] * factorial(j);
        ans = ans % 1000003;
        j++;
        i--;
    }
    return ans + 1;
}
