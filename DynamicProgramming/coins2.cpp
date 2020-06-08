// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if (amount == 0) {
            return 1;
        } else if (len == 0) {
            return 0;
        }
        
        int** storage = new int*[len]();    
        for (int i=0 ; i<len ; i++) {
            storage[i] = new int[amount+1]();
            storage[i][0] = 1;
        }
        
        for (int col=1 ; col<=amount ; col++) {
            if (col % coins[0] == 0) {
                storage[0][col] = 1;
            }
        }
        
        for (int row=1 ; row<len ; row++) {
            for (int col=1 ; col<coins[row] && col<=amount ; col++) {
                storage[row][col] = storage[row-1][col];
            }
            for (int col=coins[row] ; col<=amount ; col++) {
                storage[row][col] = storage[row-1][col] + storage[row][col - coins[row]];
            }
        }
        
        // -------------- dp storage ----------------
        // for (int row=0 ; row<len ; row++) {
        //     for (int col=0 ; col<=amount ; col++) {
        //         cout << storage[row][col] << " ";
        //     }
        //     cout << endl;
        // }
        
        return storage[len-1][amount];
    }
};