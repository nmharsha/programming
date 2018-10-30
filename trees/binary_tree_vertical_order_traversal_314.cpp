/**
 * Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 *
 * If two nodes are in the same row and column, the order should be from left to right.
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector< vector< int > > result;
        map< int, vector< int > > m;
        queue< pair< TreeNode*, int > > q;

        if ( !root ) return result;
        q.push( make_pair( root, 0 ) );

        while ( !q.empty() ) {
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            q.pop();

            if ( m.find( level ) == m.end() ) {
                vector< int > v;
                v.push_back( curr->val );
                m[ level ] = v;
            } else {
                m[ level ].push_back( curr->val );
            }

            if ( curr->left ) q.push( make_pair( curr->left, level - 1 ) );
            if ( curr->right ) q.push( make_pair( curr->right, level + 1 ) );
        }

        for ( auto it = m.begin(); it != m.end(); ++it ) {
            result.push_back( it->second );
        }

        return result;
    }
};
