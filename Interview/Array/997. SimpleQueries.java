/*

You are given an array A having N integers.

You have to perform the following steps in a given order.

generate all subarrays of A.
take the maximum element from each subarray of A and insert it into a new array G.
replace every element of G with the product of their divisors mod 1e9 + 7.
sort G in descending order
perform Q queries
In each query, you are given an integer K, where you have to find the Kth element in G.

Note: Your solution will run on multiple test cases so do clear global variables after using them.


Input Format

The first argument given is an Array A, having N integers.
The second argument given is an Array B, where B[i] is the ith query.
Output Format

Return an Array X, where X[i] will have the answer for the ith query.
Constraints

1 <= N <= 1e5
1 <= A[i] <= 1e5
1 <= Q <= 1e5
1 <= k <= (N * (N + 1))/2 
For Example

Input:
    A = [1, 2, 4]
    B = [1, 2, 3, 4, 5, 6]
Output:
    X = [8, 8, 8, 2, 2, 1]
   
Explanation:
    subarrays of A	  maximum element
    ------------------------------------
    1. [1]							1
    2. [1, 2]						2
    3. [1, 2, 4]					4
    4. [2]							2
    5. [2, 4]						4
    6. [4]							4

	original
	G = [1, 2, 4, 2, 4, 4]
	
	after changing every element of G with product of their divisors
	G = [1, 2, 8, 2, 8, 8]
	
	after sorting G in descending order
	G = [8, 8, 8, 2, 2, 1]
  
  */

public class Solution {
    public ArrayList<Integer> solve(ArrayList<Integer> as, ArrayList<Integer> qs) {
        int n = as.size();
        Stack<Integer> st = new Stack<Integer>();
        int[] left = new int[n];
        for (int i = 0; i < n; ++i) {
            while (!st.isEmpty() && as.get(st.peek()) < as.get(i)) st.pop();
            left[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }
        st = new Stack<Integer>();
        int[] right = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!st.isEmpty() && as.get(st.peek()) <= as.get(i)) st.pop();
            right[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }
        Map<Integer, Integer> prod = new HashMap<Integer, Integer>();
        List<int[]> counts = new ArrayList<int[]>();
        for (int i = 0; i < n; ++i) {
            int cnt = (i - left[i]) * (right[i] - i);
            int a = as.get(i);
            Integer pr = prod.get(a);
            if (pr == null) {
                pr = toProd(a);
                prod.put(a, pr);
            }
            counts.add(new int[]{pr, cnt});
        }
        Collections.sort(counts, new Comparator<int[]>(){
            public int compare(int[] o1, int[] o2) {
                return o2[0] - o1[0];
            }
        });
        int[] vals = new int[n];
        long[] bounds = new long[n];
        for (int i = 0; i < n; ++i) {
            int [] c = counts.get(i);
            vals[i] = c[0];
            bounds[i] = c[1];
            if (i > 0) bounds[i] += bounds[i - 1];
            if (bounds[i] > Integer.MAX_VALUE * 2L) bounds[i] = Integer.MAX_VALUE * 2L;
        }
        ArrayList<Integer> res = new ArrayList<Integer>();
        for (int q : qs) {
            int pos = Arrays.binarySearch(bounds, q);
            if (pos < 0) {
               pos = -1 - pos; 
            }
            res.add(vals[pos]);
        }
        return res;
    }
    
    private final static long b = (long) (1e9 + 7);
    
    private int toProd(int a) {
        long res = a;
        for (int d = 2; d * d <= a; ++d) {
            if (a % d != 0) continue;
            int m = (d * d == a) ? d : a;
            res = (res * m) % b;
        }
        return (int) res;
    }
}
