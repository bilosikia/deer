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
    ListNode* swapPairs(ListNode* head) {
        ListNode *first = nullptr, *second = nullptr, *pre = nullptr;
        if(!head || !head->next) {
            return head;
        }
        first = head->next;
        second = head;
        while(true) {
            second->next = first->next;
            first->next = second;
            if(pre) {
                pre->next = first;
            }
            else {
                head = first;
            }
            pre = second;
            second = second->next;
            if(!second || !second->next) {
                break;
            }
            first = second->next;
        }
        return head;
    }
};