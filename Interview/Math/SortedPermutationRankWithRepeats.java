/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations.
Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' : 
aab
aba
baa
The answer might not fit in an integer, so return your answer % 1000003

 NOTE: 1000003 is a prime number
NOTE: Assume the number of characters in string < 1000003 

*/

import java.math.BigInteger;
public class Solution {
    public int findRank(String A) {
        BigInteger rank = BigInteger.ONE;
        BigInteger permCount = BigInteger.ONE;
        Map<Character, Integer> chars = new HashMap<Character,Integer>();
        
        for(int i = A.length() - 1; i > -1; i--) {
            char x = A.charAt(i);
            int count = chars.containsKey(x) ? chars.get(x) + 1 : 1;
            chars.put(x, count);
            for(Map.Entry<Character,Integer> e: chars.entrySet()) {
                if(e.getKey() < x) {
                    rank = rank.add((permCount.multiply(BigInteger.valueOf(e.getValue()))).divide(BigInteger.valueOf(count)));
                }
            }
            permCount = permCount.multiply(BigInteger.valueOf(A.length() - i)).divide(BigInteger.valueOf(count));
        }
        return rank.remainder(BigInteger.valueOf(1000003)).intValue();
    }
}


/*
CPP
*/

/*

#define MOD 1000003
#define ll long long int

int indexOf(char ch) {
    if (ch >= 'a' and ch <= 'z') {
        return ch - 'a';
    }
    return ch - 'A' + 30;
}

ll factMod(ll num) {
    ll res = 1;
    for (ll i = 1; i <= num; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

ll fact(ll num) {
    ll res = 1;
    for (ll i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

ll powerMod (ll base, ll power, ll mod) {
    ll res = 1;
    base = base % mod;
    while (power > 0) {
        if (power % 2 == 1) {
            res = (res * base) % mod;
        }
        power = power >> 1;
        base = (base * base) % mod;
    }
    return res; 
}


int permute(string s) {
    int n = s.size();
    vector<int>freq(60, 0);
    for (int i = 0; i < n; i++) {
        freq[indexOf(s[i])] += 1;
    }
    int res = factMod(n);
    for (int i = 0; i < 60; i++) {
        if (freq[i] > 1) {
            res = (res * powerMod(fact(freq[i]), MOD - 2, MOD)) % MOD; 
        }
    }
    return res;
}

int Solution::findRank(string A) {
    int n = A.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        vector<bool>taken(60, false);
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j] and taken[indexOf(A[j])] == false) {
                taken[indexOf(A[j])] = true;
                swap(A[i], A[j]);
                ans = (ans + permute(A.substr(i + 1))) % MOD;
                swap(A[i], A[j]);
            }
        }
    }
    ans = (ans + 1) % MOD;
    return ans;
}

*/
