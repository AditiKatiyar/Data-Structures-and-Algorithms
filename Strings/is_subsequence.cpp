// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if (len1 == 0 && len2 == 0) {
            return true;
        }
        int j=0;
        for (int i=0 ; i<len2 ; i++) {
            if (s[j] == t[i]) {
                j++;
            }
            if (j == len1) {
                return true;
            }
        }
        
        return false;
    }
};