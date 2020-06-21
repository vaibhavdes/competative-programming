/*

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)


*/

bool isValid(string A) {
    if (A.size() > 1 && s[0]  ==  '0')
        return false;
    if (stoi(A) <= 255 && stoi(A) >= 0)
        return true;
    else
        return false;
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    if (A.size() > 12 || A.size() < 4)
        return ans;

    for (int i = 1; i < 4; i++) {
        string first  =  A.substr(0, i);
        if (!isValid(first))
            continue;
        for (int j = 1; i + j < A.size() && j < 4; j++) {
            string second  =  A.substr(i, j);
            if (!isValid(second))
                continue;
            for (int k = 1; i + j + k < A.size() && k < 4; k++) {
                string third = A.substr(i + j, k);
                string fourth = A.substr(i + j + k);
                if (isValid(third) && isValid(fourth)) {
                    string current  =  first + "." + second + "." + third + "." + fourth;
                    ans.push_back(current);
                }
            }
        }
    }

    return ans;
}
