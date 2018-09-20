/**
 * Given a singly linked list, determine if it is a palindrome.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  bool isPalindrome( ListNode* head ) {
    if ( head == NULL || head->next == NULL ) {
      return true;
    }
    int lengthOfLL = 0;
    ListNode* fast = head;
    ListNode* slow = head;

    while ( fast != NULL ) {
      fast = fast->next;
      if ( fast != NULL ) {
        fast = fast -> next;
      }
        cout << "Slow updated" << endl;
      slow = slow->next;
    }

    ListNode* prev = NULL;

    while ( slow->next != NULL ) {
      ListNode* temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
    }
    slow->next = prev;

    while( head != NULL && slow != NULL ) {
      if( head->val != slow->val ) {
        return false;
      }
      head = head->next;
      slow = slow->next;
    }
    return true;
  }
};
