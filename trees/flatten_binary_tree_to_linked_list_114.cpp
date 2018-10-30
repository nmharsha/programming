/**
 * Given a binary tree, flatten it to a linked list in-place.
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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if ( !left ) {
            flatten( right );
        } else {
            flatten( left );
            root->right = left;
            if ( right ) {
                while ( left->right != nullptr ) {
                    left = left->right;
                }
                left->right = right;
                flatten( right );
            }
        }
    }
};
