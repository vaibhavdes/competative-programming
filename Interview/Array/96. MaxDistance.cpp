/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

*/

int Solution::maximumGap(const vector<int> &A) {
    int size = A.size();
    int ans = 0;
    vector<pair<int,int>> v;
    for(int i=0; i<size; i++) {
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    int maxn=v[size-1].second;
    for(int i=size-2;i>=0;i--) {
        ans = max(ans,maxn-v[i].second);
        maxn = max(maxn, v[i].second);
    }
    return ans;
}
