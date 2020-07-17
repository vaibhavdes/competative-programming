/*

Problem Description

Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.

NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

You are expected to use Trie in an Interview for such problems



Problem Constraints
1 <= No.of reviews <= 200
1 <= No. of words in a review <= 1000
1 <= Length of an individual review <= 10,000
1 <= Number of Good Words <= 10,000
1 <= Length of an individual Good Word <= 4
All the alphabets are lower case (a - z)


Input Format
First argument is a string A containing "Good Words" separated by "_" character

Second argument is a vector B of strings containing Hotel Reviews. Review strings are also separated by "_" character.



Output Format
Return a vector of integers which contain the original indexes of the reviews in the sorted order of reviews.



Example Input
Input 1:

 A = "cool_ice_wifi"
 B = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]


Example Output
Output 1:

 [2, 0, 1]


Example Explanation
Explanation 1:

 sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]

*/



vector<string> split(string s) {
    vector<string> words;
    string word;    s += '_';
    for (auto ch: s) {
        if (ch != '_')
            word += ch;
        else if (word.size()) {
            words.push_back(word);
            word = "";
        }
    }
    
    return words;
}


vector<int> Solution::solve(string A, vector<string> &B) {
    vector<string> ordered_words = split(A);
    unordered_set<string> good_words = {ordered_words.begin(), ordered_words.end()};
    unordered_map<int, int> freq;
    vector<vector<string>> samples;
    vector<int> answer(B.size());

    for (auto word: B)
    	samples.push_back(split(word));

    for (int i = 0; i < B.size(); i += 1) {
    	for (auto word: samples[i])
    		freq[i] += (good_words.find(word) != good_words.end());
    }
    
    for (int i = 0; i < answer.size(); i += 1)
    	answer[i] = i;

    stable_sort(answer.begin(), answer.end(), [&](int i, int j) {
    	// return i < j, actually i > j
    	if (freq[i] != freq[j])
    		return (freq[j] != 0 && freq[i] > freq[j]) || (freq[j] == 0);
    	return false;
    });
    
    return answer;
}
