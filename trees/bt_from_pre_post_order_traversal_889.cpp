/**
 * Return any binary tree that matches the given preorder and postorder traversals.
 * Values in the traversals pre and post are distinct positive integers.
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
    TreeNode* constructFromPrePost( vector<int> &pre, vector<int> &post ) {
        if ( pre.size() <= 0 ) {
            return nullptr;
        }
        int rootVal = pre[ 0 ];
        TreeNode* root = new TreeNode( rootVal );
        if ( pre.size() == 1 ) {
            return root;
        }
        vector<int>::iterator posItr = find( post.begin(), post.end(), pre [ 1 ] );
        int pos = distance(post.begin(), posItr);
        vector<int> leftPre( pre.begin() + 1, pre.begin() + pos + 1 + 1 );
        vector<int> leftPost( post.begin(), post.begin() + pos + 1 );
        vector<int> rightPre( pre.begin() + pos + 2, pre.end() );
        vector<int> rightPost( post.begin() + pos + 1, post.end() - 1 );
        root->left = constructFromPrePost( leftPre, leftPost );
        root->right = constructFromPrePost( rightPre, rightPost );
        return root;
    }
};
