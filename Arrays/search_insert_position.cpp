// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i=0 ; i<len ; i++) {
            if (target <= nums[i]) {
                return i;
            }
        }
        return len;
    }
};