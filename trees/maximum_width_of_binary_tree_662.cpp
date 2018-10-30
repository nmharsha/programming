/**
 * Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
 *
 * The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
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
    int widthOfBinaryTree(TreeNode* root) {
        int result = INT_MIN;
        int count = 0;
        queue< pair< TreeNode*, int > > q;
        q.push( make_pair( root, count ) );
        q.push( make_pair( nullptr, 0) );
        count++;
        int left = INT_MAX;
        int right = INT_MIN;

        while ( !q.empty() ) {
            TreeNode* curr = q.front().first;
            int curr_ind = q.front().second;
            q.pop();

            if ( curr_ind < left ) left = curr_ind;
            if ( curr_ind > right ) right = curr_ind;

            if ( curr->left ) q.push( make_pair( curr->left, curr_ind*2 + 1 ) );
            count++;
            if ( curr->right ) q.push( make_pair( curr->right, curr_ind*2 + 2 ) );
            count++;

            if ( q.front().first == nullptr ) {
                q.pop();
                if ( ( right - left + 1 ) > result ) {
                    result = right - left + 1;
                }
                left = INT_MAX;
                right = INT_MIN;
                if ( !q.empty() ) q.push( make_pair( nullptr, 0) );
            }
        }

        return result;
    }
};

