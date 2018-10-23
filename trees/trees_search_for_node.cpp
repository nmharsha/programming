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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue< TreeNode* > q;
        q.push( root );
        while ( !q.empty() ) {
			TreeNode* curr = q.front();
            q.pop();
			if ( curr->val == val )
				return curr;
            if ( curr->left != NULL )
                q.push( curr->left );
            if ( curr->right != NULL )
                q.push( curr->right );
        }
		return NULL;
    }
};

