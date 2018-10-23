/**
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    void leafValueSequence( TreeNode* root, vector< int > &s ) {
        if( root->left != NULL ) {
            leafValueSequence( root->left, s );
        }
        if ( root->right != NULL ) {
            leafValueSequence( root->right, s );
        }
        if ( root->left == NULL && root->right == NULL ) {
            s.push_back( root->val );
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector< int > s1;
        vector< int > s2;
        leafValueSequence( root1, s1 );
        leafValueSequence( root2, s2 );
        if ( s1 == s2 ) {
            return true;
        }
        return false;
    }
};
