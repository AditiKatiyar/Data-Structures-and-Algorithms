// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
#include <algorithm>
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        int len = costs.size();
        vector<int> refund;
        for (int i=0 ; i<len ; i++) {
            cost += costs[i][0];
            refund.push_back(costs[i][1] - costs[i][0]);
        }
        sort(refund.begin(), refund.end());
        
        for (int i=0 ; i<len/2 ; i++) {
            cost += refund[i];
        }
        
        return cost;
    }
};