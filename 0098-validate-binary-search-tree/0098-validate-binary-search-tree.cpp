/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return inorder(root, prev);
        
    }
    private:
    bool inorder(TreeNode* node, long &prev) {
        if (!node) return true;
        
        if (!inorder(node->left, prev)) return false;
        if (node->val <= prev) return false;
        prev = node->val;
        return inorder(node->right, prev);
    }
};