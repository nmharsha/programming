/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root) {
        bool valid = false;
        double prev = DBL_MIN;

        if ( root == nullptr ) {
            return true;
        }

        stack< TreeNode* > s;
        TreeNode* curr = root;

        do {
            if ( curr != nullptr ) {
                s.push( curr );
                curr = curr->left;
            } else {
                TreeNode* popped_item = s.top();
                s.pop();
                if ( popped_item->val <= prev ) {
                    return false;
                } else {
                    prev = popped_item->val;
                }
                curr = popped_item->right;
            }
        } while ( !s.empty() || curr != nullptr );

        return true;
    }
};
