/*

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]


*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int size = A.size();
    vector<vector<int>> v(2*size-1);
    int count = 0;
    for(int i = 0; i<size;i++){
        int x= 0, y =i;
        while(x<size && y>=0) {
            v[count].push_back(A[x][y]);
            x++;
            y--;
        }
        count++;
    }
    for(int i=1;i<size;i++) {
        int x=i,y=size-1;
        while(x<size && y>=0) {
            v[count].push_back(A[x][y]);
            x++;
            y--;
        }
        count++;
    }
    return v;
}
