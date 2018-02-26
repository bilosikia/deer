#include <vector>
#include <algorithm>

using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> heap;
        for(auto v : lists) {
            if(v) {
                heap.push_back(v);
            }
        }
        auto comp = [](ListNode *a, ListNode *b)->bool {
            return a->val > b->val; // for mini heap
        };
        make_heap(heap.begin(), heap.end(), comp);

        ListNode *head = nullptr;
        ListNode *last = nullptr;
        while(!heap.empty()) {
           pop_heap(heap.begin(), heap.end(), comp);
           ListNode *top = heap.back();
           heap.pop_back();
           if(top->next) {
               heap.push_back(top->next);
               push_heap(heap.begin(), heap.end(), comp);
           }

           if(head == nullptr) {
               head = top;
               head->next = nullptr;
               last = head;
           }
           else {
               last->next = top;
               last = last->next;
               top->next = nullptr; 
           }
        }
        return head;
    }
};
