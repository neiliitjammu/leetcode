/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int n) {
         ListNode *fast = head;
        ListNode *slow = head;
        int k = 1;
        while(k != n)
        {
            fast = fast->next;
            k++;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *last = slow;
        ListNode *first = head;
        int num = 1;
        while(num != n)
        {
            num++;
            first = first->next;
        }
        swap(first->val,last->val);
        return head;
    }
};