/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 *
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
	int sumTotal;

    void doSumTotal( TreeNode* root, int val ) {
        if ( root == NULL ) {
            return;
        }
        if( root->left == NULL && root->right == NULL ) {
            sumTotal += val*10 + root->val;
            return;
        }
        if ( root->left != NULL ) {
            doSumTotal( root->left, val*10 + root->val );
        }
        if ( root->right != NULL ) {
            doSumTotal( root->right, val*10 + root->val );
        }
    }

    int sumNumbers( TreeNode* root ) {
        sumTotal = 0;
        doSumTotal( root, 0 );
        return sumTotal;
    }
};
