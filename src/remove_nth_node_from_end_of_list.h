/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head;
        ListNode *second = nullptr;
        int flag = 1; // relative head number
        while(first->next) {
            flag++;
            if(flag == n + 1) {
                second = head;
            }
            else if(flag > n + 1) {
                second = second->next;
            }
            first = first->next;
        }

        ListNode *removedNode = nullptr;
        if(second == nullptr) {
            removedNode = head;
            head = head->next;
        }
        else {
            removedNode = second->next;
            second->next = second->next->next;
        }
        delete removedNode;
        return head;
    }
};
