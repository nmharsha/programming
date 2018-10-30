/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue< TreeNode* > q;
        vector< vector< int > > result;
        if ( root == NULL )
            return result;
        vector< int > curr;
        q.push(root);
        q.push( nullptr );
		int level = 0;
        while ( !q.empty() ) {
            TreeNode* top = q.front();
            q.pop();
            curr.push_back( top->val );
            if ( top->left != NULL ) {
                q.push( top->left );
            }
            if ( top->right != NULL ) {
                q.push( top->right );
            }
            if ( q.front() == nullptr ) {
                q.pop();
				if ( level%2 == 1 ) {
                    reverse( curr.begin(), curr.end() );
				}
                result.push_back( curr );
                curr.clear();
                if ( !q.empty() )
                    q.push(nullptr);
                level++;
            }
        }
        return result;
    }
};
