// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/
#include <cstdlib>
class Solution {
public:
    
    vector<double> arr;
    Solution(vector<int>& w) {
        int len = w.size();
        int sum = 0;
        for (int i=0 ; i<len ; i++) {
            sum += w[i];
        }
        
        double l = 0.0;
        double h;
        for (int i=0 ; i<len ; i++) {
            h = l + (double(w[i]) / sum);
            arr.push_back(h);
            l = h;
            // cout << arr[i] << " ";
        }
    }
    
    int pickIndex() {
        double d = (double) rand()/RAND_MAX;
        for (int i=0 ; i<arr.size() ; i++) {
            if (d <= arr[i]) {
                return i;
            }
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */