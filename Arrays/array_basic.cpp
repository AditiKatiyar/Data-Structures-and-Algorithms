#include <cmath>

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
};