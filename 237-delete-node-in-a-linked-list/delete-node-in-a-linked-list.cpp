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
        ListNode *neil;
        neil = node;
        node = node->next;
        neil->val = node->val;
        neil->next = node->next;
        node->next = NULL;
    }
};