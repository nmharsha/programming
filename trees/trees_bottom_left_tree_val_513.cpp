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
    
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        int maxLevelSoFar = 0;
        q.push(root);
        q.push(NULL);
        int result = root->val;
        while(!q.empty()) {
            TreeNode* next = q.front();
            q.pop();
            if(next->left == NULL && next->right == NULL) {
                if(level > maxLevelSoFar) {
                    result = next->val;
                    maxLevelSoFar = level;
                }
            } else {
                if(next->left!=NULL) {
                    q.push(next->left);
                }
                if(next->right != NULL) {
                    q.push(next->right);
                }
            }
            if(q.front() == NULL) {
                q.pop();
                level++;
                if (!q.empty())
                    q.push(NULL);
            }
        }
        return result;
    }
};
