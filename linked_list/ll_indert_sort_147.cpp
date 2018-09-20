/**
 * Sort a linked list using insertion sort.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode* insertionSortList( ListNode* head ) {
    if ( head == NULL || head->next== NULL ) {
      return head;
    }
    ListNode* curr = head->next;
    head->next = NULL;
    while ( curr != NULL ) {
      ListNode* prev = NULL;
      ListNode* temp = curr->next;
      ListNode** headRef = &head;
      while( ( *headRef ) != NULL ) {
        if ( curr->val <= ( *headRef )->val ) {
          curr->next = *headRef;
          *headRef = curr;
          break;
        }
        headRef = &( *headRef )->next;
      }
      if ( ( *headRef ) == NULL ) {
        *headRef = curr;
        curr->next = NULL;
      }
      curr = temp;
    }
    return head;
  }
};
