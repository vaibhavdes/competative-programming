/*

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/


vector<vector<int> > Solution::solve(int A) {
    if (A == 0) { return {}; }
    vector<vector<int>> v(A);
    v[0].push_back(1);
    for (int i = 1; i < A; ++i) {
        v[i].push_back(1);
        for (int j = 1; j < i; ++j) {
            v[i].push_back(v[i-1][j] + v[i-1][j-1]);
        }
        v[i].push_back(1);
    }
    return v;
}
