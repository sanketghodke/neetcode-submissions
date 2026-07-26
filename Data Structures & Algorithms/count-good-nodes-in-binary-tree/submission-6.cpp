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
    int countNodes(TreeNode* root, int maxi){
        if(root ==NULL) return 0;
        
        int result = root->val >= maxi ? 1 : 0;
        maxi = max(root->val, maxi);
        result = result + countNodes(root->left, maxi);
        result = result + countNodes(root->right, maxi);
        return result;

    }
    int goodNodes(TreeNode* root) {
        return countNodes(root, INT_MIN);
    }
};
