// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0 || n == INT_MIN || n == INT_MAX) {
            return false;
        }
        return (n & (n-1)) == 0;
    }
};