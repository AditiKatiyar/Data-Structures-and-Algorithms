// https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int zeroIndex = -1;
        int oneIndex;
        int twoIndex = len;
        while (zeroIndex+1 < len && nums[zeroIndex+1] == 0) {
            zeroIndex++;
        }
        while (twoIndex-1 > zeroIndex && nums[twoIndex-1] == 2) {
            twoIndex--;
        }
        
        oneIndex = zeroIndex+1;
       
        while (oneIndex < twoIndex) {
            if (nums[oneIndex] == 0) {
                zeroIndex++;
                if (zeroIndex < oneIndex) {
                    nums[oneIndex] = nums[zeroIndex];
                    nums[zeroIndex] = 0;
                } else {
                    oneIndex++;
                }
            } else if (nums[oneIndex] == 2) {
                twoIndex--;
                nums[oneIndex] = nums[twoIndex];
                nums[twoIndex] = 2;
            } else {
                oneIndex++;
            }
    
        }
    }
};