/**
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 */

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd_head = nullptr;
        ListNode* even_head = nullptr;

        ListNode** odd = nullptr;
        ListNode** even = nullptr;

        int count = 0;
        ListNode* curr = head;
        while ( curr ) {
            if ( count % 2 ) {
                // cout << curr->val << endl;
                if ( !odd ) {
                    odd = &curr;
                    odd_head = *odd;
                } else {
                    *odd = curr;
                }
                odd = &( (*odd)->next );
            } else {
                if ( !even ) {
                    even = &curr;
                    even_head = *even;
                } else {
                    *even = curr;
                }
                even = &( (*even)->next );
            }
            curr = curr->next;
            count++;
        }
        *odd = nullptr;

        *even = odd_head;
        return even_head;
    }
};

