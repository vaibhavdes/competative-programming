/*

Problem Description

It’s Tushar’s birthday today and he has N friends.

Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].

Today being his birthday, his friends have planned to give him birthday bombs (kicks).

Tushar's friends know Tushar's pain bearing limit and would hit accordingly.

If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.

Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

NOTE:

[a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) ... .
Input cases are such that the length of the answer does not exceed 100000.


Problem Constraints
1 <= N <= 100

1 <= A <= 15 * 106

1 <= B[i] <= 105



Input Format
The first argument contains an integer, A of length N.

The second argument contains an array of integers B.



Output Format
Return an array of integer, as described in the problem statement.



Example Input
Input 1:

 A = 12
 B = [3, 4]
Input 2:

 A = 11
 B = [6, 8, 5, 4, 7]


Example Output
Output 1:

 [0, 0, 0, 0]
Output 2:

 [0, 2]


*/


   public ArrayList<Integer> solve(int A, ArrayList<Integer> B) {
            
        ArrayList<Integer> result = new ArrayList<Integer>();
        if(null == B || B.isEmpty() || A <=0) return result;

        int min = B.get(0);
        for (int i = 1; i < B.size(); i++) {
            min = Math.min(min, B.get(i));
        }
        int maxKicks = A / min;

        int temp = 0;
        while (temp < B.size() && A > 0) {
            if (A - B.get(temp) < 0) {
                temp++;
                continue;
            }
            if (1 + result.size() + (A - B.get(temp)) / min < maxKicks) {
                temp++;
                continue;
            }
            result.add(temp);
            A = A - B.get(temp);
        }

        return result;
    }
