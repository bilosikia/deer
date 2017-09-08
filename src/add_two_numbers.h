#pragma once

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *header = nullptr;
        ListNode *last = nullptr;
        auto ptr1 = l1;
        auto ptr2 = l2;
        int carry = 0;

        while (true) {
            if (ptr1 != nullptr && ptr2 != nullptr) {
                int sumResult = ptr1->val + ptr2->val + carry;
                int low = sumResult % 10;
                carry = sumResult / 10;
                ListNode *node = new ListNode(low);
                if (last == nullptr) {
                    header = node;
                    last = node;
                } else {
                    last->next = node;
                    last = node;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } else {
                break;
            }
        }
        auto f = [&last, &header, &carry](ListNode *ptr) {
            while (ptr) {
                int sumResult = ptr->val + carry;
                int low = sumResult % 10;
                carry = sumResult / 10;
                ListNode *node = new ListNode(low);
                if (last == nullptr) {
                    header = node;
                    last = node;
                } else {
                    last->next = node;
                    last = node;
                }
                ptr = ptr->next;
            }
        };
        f(ptr1);
        f(ptr2);
        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            last->next = node;
        }
        return header;
    }
};