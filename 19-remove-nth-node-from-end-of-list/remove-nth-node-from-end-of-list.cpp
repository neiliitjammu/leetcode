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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;
        if(head->next == NULL)
        {
            return NULL;
        }
        while(temp != NULL)
        {
          length++;
          temp = temp->next;
        }
        int start = length - n + 1;
        temp = head;
        int num = 1;
        while(num != start)
        {
            temp = temp->next;
            num++;
        }
        if(temp == head)
        {
            head = head->next;
            return head;
        }
        ListNode* prev = head;
        while(prev->next != temp)
        {
            prev = prev->next;
        }
        prev->next = prev->next->next;
        delete temp;
        return head;
    }
};