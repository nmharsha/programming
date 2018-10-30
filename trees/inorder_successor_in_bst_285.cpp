/**
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 *
 * Note: If the given node has no in-order successor in the tree, return null.
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if ( p->right ) {
            TreeNode* temp = p->right;
            while ( temp->left ) {
                temp = temp->left;
            }
            return temp;
        }

        TreeNode* curr = root;
        TreeNode* left_turn = nullptr;

        while ( curr != p ) {
            if ( curr->val >= p->val ) {
                left_turn = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return left_turn;
    }
};
