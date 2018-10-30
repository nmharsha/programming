/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if ( !head ) return nullptr;
        ListNode** slow = &head;
        ListNode** fast = &head;

        while ( *fast ) {
            *fast = ( *fast )->next;
            if ( *fast ) {
                *fast = ( *fast )->next;
                *slow = ( *slow )->next;
            }
        }

        ListNode* ll_root = *slow;
        *slow = nullptr;

        TreeNode* l = sortedListToBST( head );
        TreeNode* r = sortedListToBST( ll_root->right );
        TreeNode* root = new TreeNode( ll_head->val );
        root->left = l;
        root->rigth = r;

        return root;
    }
};
