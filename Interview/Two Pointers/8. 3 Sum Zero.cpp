/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2)


*/


vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    long long sum=0, n=A.size();
    vector<vector<int>> ans;
    for(int i=0;i<n-2;i++){
        if(i>0&&A[i]==A[i-1]) continue;
        int j=i+1, k=n-1;
        while(j<k){
            sum=1ll*A[i]+1ll*A[j]+1ll*A[k];
            if(sum==0){
                vector<int> tmp;
                tmp.push_back(A[i]);
                tmp.push_back(A[j]);
                tmp.push_back(A[k]);
                ans.push_back(tmp);
            }
            if(sum>0)k--;
            else if(sum<0)j++;
            else if(sum==0){
                j++;
                while(j<k && A[j]==A[j-1])j++;
            }
        }
    }
    return ans;
}
