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
        TreeLinkNode* head, tail = nullptr;

        while ( root ) {
            if ( root->left ) {
                if ( tail ) {
                    tail->next = root->left;
                    tail = tail->next;
                } else {
                    head = root->left;
                    tail = root->left;
                }
            }

            if ( root->right ) {
                if ( tail ) {
                    tail->next = root->right;
                    tail = tail->next;
                } else {
                    head = root->right;
                    tail = root->right;
                }
            }

            root = root->next;

            if ( !root ) {
                root = head;
                head = nullptr;
                tail = nullptr;
            }
        }
    }
};
