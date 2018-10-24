/**
 * Definition for a binary tree node.
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int result = -1;
        // s.push( root );
		TreeNode* curr = root;
        int count = 0;
        do {
			if ( curr != nullptr ) {
				s.push( curr );
				curr = curr->left;
			} else {
				TreeNode* popped_item = s.top();
				s.pop();
                count++;
                if ( count == k ) {
                    result = popped_item->val;
                }
                curr = popped_item->right;
			}
		}
        while ( !s.empty() || curr != nullptr );
        return result;
    }
};
