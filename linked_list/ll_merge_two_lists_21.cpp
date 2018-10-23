/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1Ref = l1;
        ListNode** l1HeadRef = &l1;
        while( l2 != NULL ) {
            if(*l1HeadRef == NULL) {
                *l1HeadRef = l2;
                break;
            }
            if ( (*l1HeadRef)->val <= l2->val) {
                l1HeadRef = &((*l1HeadRef)->next);
            } else {
                ListNode* temp = *l1HeadRef;
                *l1HeadRef = l2;
                l2 = l2->next;
                (*l1HeadRef)->next = temp;
                l1HeadRef = &((*l1HeadRef)->next);
            }
        }
        return l1;
    }
};
