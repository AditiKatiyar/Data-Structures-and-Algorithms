/*
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 * The order of output does not matter.
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 */

class Solution {
public:
    
    bool isAnagram(int* a, int* b, int len) {
        for (int i=0 ; i<len ; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int pLen = p.length();
        int sLen = s.length();
        vector<int> ans;
        
        if (sLen < pLen) {
            return ans;
        }
        
        int* pMap = new int[26](); // creating maps to keep count on chars 'a' to 'z'.
        for (int i=0 ; i<pLen ; i++) {
            pMap[p[i] - 'a']++;
        }
        
        int* sMap = new int[26]();
        for (int i=0 ; i<pLen ; i++) {
            sMap[s[i] - 'a']++;
        }
        
        if (isAnagram(pMap, sMap, 26)) {
            ans.push_back(0);
        }
        
        for (int i=1 ; i<=sLen-pLen ; i++) {
            sMap[s[i-1] - 'a']--; // reduce count of chracter that is skipped in sliding window
            sMap[s[i+pLen-1] - 'a']++; // increment count. of character that is included in sliding window
            if (isAnagram(pMap, sMap, 26)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};