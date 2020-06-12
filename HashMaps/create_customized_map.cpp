// https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3358/

#include <map>

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    map<int, bool> m;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ans;
        if (m.count(val) <= 0) {
            ans = true;
        } else {
            ans = false;
        }
        m[val] = true;
        return ans;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ans;
        if (m.count(val) > 0) {
            ans = true;
        } else {
            ans = false;
        }
        m.erase(val);
        return ans;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = m.size();
        if (size == 0) {
            return -1;
        }
        int num = (rand() % size) + 1;
        int count = 1;
        for (map<int, bool>::iterator it = m.begin() ; it !=m.end() ; it++) {
            if (count == num) {
                return it->first;
            }
            count++;
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */