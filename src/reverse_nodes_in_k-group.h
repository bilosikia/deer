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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // p is the point of point of pre k list's last node'next
        // pre is the point of previous node
        ListNode **p = &head, *pre = head; 
        ListNode *n = nullptr;
        if(k == 1) {
            return head;
        }
        if(pre && pre->next) {
            n = pre->next;
        }
        else {
            return head;
        }

        int flag = 1;
        ListNode *f = head;
        ListNode *result = nullptr;
        int i = 0;
        for(; i < k && f; i++) {
            f = f->next;
        }
        if(i < k) {
            return head;
        }
        while(pre && n) {
            if(f) {
                f = f->next;
            }
            flag++;
            ListNode *t = n->next;
            n->next = pre;
            pre = n;
            n = t;

            if(flag == k) {
                flag = 1;
                ListNode **temp = &((*p)->next);
                (*p)->next = n;
                *p = pre;
                p = temp;
                
                if(!result) {
                    result = pre;
                }
                if(!f) {
                    break;
                }
                pre = n;
                if(n->next) {
                    n = n->next;
                    f = f->next;
                }
                else {
                    break;
                }
            }
        }
        if(n) {
            if(!result) {
                result = n;
            }
            *p = n;
        }
        return result;
    }
};