/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
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
    ListNode* partition(ListNode* head, int x) {
        if(!head || head->next == nullptr) return head;
        ListNode* less = nullptr;
        ListNode* great = nullptr;
        ListNode* great_head = nullptr;
        ListNode* less_head = nullptr;
        
        ListNode* curr = head;

        while ( curr ) {
            cout << curr->val << endl;
            if ( curr->val >= x ) {
                if (great) {
                    cout << "Great yes" <<endl;
                    great->next = curr;
                    great = great->next;
                } else {
                    cout << "Great null" <<endl;
                    great = curr;
                    great_head = curr;
                }
                // great = great->next;
                curr = curr->next;
                great->next = nullptr;
            } else {
                if (less) {
                    cout << "Less yes" <<endl;
                    less->next = curr;
                    less = less->next;
                } else {
                    cout << "Less null" <<endl;
                    less = curr;
                    less_head = curr;
                }
                // less = less->next;
                curr = curr->next;
                less->next = nullptr;
            }
        }
        if(less)
            less->next = great_head;
        else
            less_head = great_head;

        return less_head;
    }
};

