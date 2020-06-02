// https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3348/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    
        ListNode* currNode = node;
        ListNode* nextNode = node->next;
        
        while (nextNode != NULL) {
            currNode->val = nextNode->val;
            if (nextNode->next == NULL) {
                currNode->next = NULL;
                delete nextNode;
                break;
            } else {
                currNode = nextNode;
                nextNode = nextNode->next;
            }
        }
        
    }
};