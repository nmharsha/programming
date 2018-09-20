/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode* swapPairs( ListNode* head ) {
    ListNode** headRef = &head;
    while( (*headRef) != NULL && ((*headRef)->next) != NULL ) {
      ListNode* temp = *headRef;
      *headRef = (*headRef)->next;
      temp->next = (*headRef)->next;
      (*headRef)->next = temp;
      headRef = &(temp->next);
    }
    return head;
  }
};
