/*

You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.

*/


vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<int> res;
    map<int,int> temp;
    for(int i=0;i<A.size();i++)
    {
        temp.insert({A[i],B[i]});
    }
     for(auto j=temp.rbegin(); j!=temp.rend(); j++)
    {
        int v1=j->first;
        int v2=j->second;
        res.insert(res.begin()+v2,v1);
    }
    return res;
}
