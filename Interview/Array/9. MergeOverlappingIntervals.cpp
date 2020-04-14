/*

Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool customComparator(Interval a, Interval b){
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    sort(A.begin(),A.end(),customComparator);
    vector<Interval> result;
    int n = A.size();
    result.push_back(A[0]);
    for(int i = 1; i<n; i++) {
        if(A[i].start <= result[result.size()-1].end)
            result[result.size()-1].end = max(result[result.size()-1].end, A[i].end);
        else
            result.push_back(A[i]);
    }
    return result;
    
}
