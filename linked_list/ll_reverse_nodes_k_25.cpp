/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. If the number
 * of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
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
    if ( head == NULL ) {
        return head;
    }
    bool flag = true;
    ListNode** headRef = &head;
      ListNode* headCopy = head;
    int llLength = 0;
    while ( headCopy != NULL ) {
      llLength++;
      headCopy = headCopy->next;
    }
      ListNode* prev = NULL;
      ListNode* curr = head;
      ListNode* next = head->next;

    while( llLength >= k ) {
        prev = NULL;
        curr = *headRef;
        next = (*headRef)->next;
        cout << "In here" << endl;
      for ( int i = 0; i < k - 1; i++ ) {
        curr->next = prev;
          prev = curr;
          ListNode* temp = next->next;
          next->next = curr;
          curr = next;
          next = temp;
      }
        ListNode* temp = *headRef;
      *headRef = curr;
        temp->next = next;
        headRef = &(temp->next);
      llLength -= k;
    }
    cout << "Im out" << head->val << endl;
    return head;
  }
};
