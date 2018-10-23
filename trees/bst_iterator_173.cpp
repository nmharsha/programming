/**
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:

    stack< TreeNode* > s;

    void adjustPointer( TreeNode* node ) {
        while ( node != nullptr ) {
            s.push( node );
            node = node->left;
        }
    }

    BSTIterator(TreeNode *root) {
        adjustPointer( root );
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if ( !s.empty() ) {
            return true;
        }
        return false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = s.top();
        s.pop();
        if ( top->right != nullptr ) {
            adjustPointer( top->right );
        }
        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
