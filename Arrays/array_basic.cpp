#include <cmath>

class Solution {
public:

    // https://leetcode.com/explore/featured/card/fun-with-arrays/521/introduction/3237/
    int findNumbers(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for (int i=0 ; i<len ; i++) {
            int digits = floor(log10(nums[i]) + 1);
            if (digits % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }

    // https://leetcode.com/explore/featured/card/fun-with-arrays/526/deleting-items-from-an-array/3247/
    int removeElement(vector<int>& arr, int val) {
        int i=0;
        int len = arr.size();
        while (i<len) {
            if (arr[i] == val) {
                break;
            }
            i++;
        }
        for (int j=i+1 ; j<len ; j++) {
            if (arr[j] != val) {
                arr[i] = arr[j];
                i++;
            }
        }
        return i;
    }

    // https://leetcode.com/explore/featured/card/fun-with-arrays/526/deleting-items-from-an-array/3248/
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int len = nums.size();
        if (len == 0 || len == 1) {
            return len;
        }
        while (j<len) {
            while (j < len && nums[i] == nums[j]) {
                j++;
            }
            if (j == len) {
                break;
            }
            i++;
            nums[i] = nums[j];
        }
        return i+1;
    }

    // https://leetcode.com/explore/featured/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/
    bool checkIfExist(vector<int>& arr) {
        map<int, bool> m;
        int len = arr.size();
        
        for (int i=0 ; i<len ; i++) {
            if (m.count(arr[i]*2) > 0 || (arr[i] % 2 == 0 && m.count(arr[i]/2)>0)) {
                return true;
            }
            m[arr[i]] = true;
        }
        
        return false;
    }

    // https://leetcode.com/explore/featured/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        int i=0;
        if (len <= 2 || arr[0] > arr[1]) {
            return false;
        }
        
        while (i+1 < len) {
            if (arr[i] < arr[i+1]) {
                i++;
            } else if (arr[i] == arr[i+1]) {
                return false;
            } else {
                break;
            }
        }
        
        if (i+1 == len) { return false; }
        
        while (i+1 < len) {
            if (arr[i] > arr[i+1]) {
                i++;
            } else {
                return false;
            }
        }
        
        return true;
    }

    // https://leetcode.com/explore/featured/card/fun-with-arrays/511/in-place-operations/3157/
    void moveZeroes(vector<int>& arr) {
        int zero = 0; // points to left most 0 element
        int len = arr.size();
        while (zero < len && arr[zero]!=0) {
            zero++;
        }
        int nonZero = zero+1; // points to the first non zero element after zero index
        while (nonZero < len && arr[nonZero] == 0) {
            nonZero++;
        }
        while (nonZero < len) {
            arr[zero] = arr[nonZero];
            arr[nonZero] = 0;
            while (zero < len && arr[zero]!=0) {
                zero++;
            }
            while (nonZero < len && arr[nonZero] == 0) {
                nonZero++;
            }
        }
    }
};