/*

Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

*/

int Solution::solve(vector<string> &A) {
    vector<double> triplets;
    int size = A.size();
    for(int i=0;i<size;i++)
        triplets.push_back(stof(A[i]));
        
    double a = triplets[0];
    double b = triplets[1];
    double c = triplets[2];
    
    for(int i =3; i< size; i++){
        if(a+b+c > 1 && a+b+c < 2)
            return 1;
        else if(a+b+c >= 2){
            if(max(a,max(b,c)) == a)
                a = triplets[i];
            else if(max(a,max(b,c)) == b)
                b = triplets[i];
            else if(max(a,max(b,c)) == c)
                c = triplets[i];
        }
         else if(a+b+c <= 1){
            if(min(a,min(b,c)) == a)
                a = triplets[i];
            else if(min(a,min(b,c)) == b)
                b = triplets[i];
            else if(min(a,min(b,c)) == c)
                c = triplets[i];
        }
    }
    
    if(a+b+c > 1 && a+b+c < 2)
        return 1;
        
    return 0;
}
