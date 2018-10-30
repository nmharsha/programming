/**
 * Given a binary tree
 *
 * struct TreeLinkNode {
 *   TreeLinkNode *left;
 *     TreeLinkNode *right;
 *       TreeLinkNode *next;
 *       }
 *       Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *
 *       Initially, all next pointers are set to NULL.
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if ( root == nullptr ) return;

        queue< TreeLinkNode* > q;
        q.push( root );
        q.push( nullptr );
        TreeLinkNode* right_ref = nullptr;

        while ( !q.empty() ) {
            TreeLinkNode* curr = q.front();
            q.pop();
            if ( right_ref ) {
                right_ref->next = curr;
            }
            right_ref = curr;
            if ( curr->left ) q.push( curr->left );
            if ( curr->right ) q.push( curr->right );
            if ( q.front() == nullptr ) {
                q.pop();
                right_ref = nullptr;
                if ( !q.empty() ) q.push( nullptr );
            }
        }
    }
};
