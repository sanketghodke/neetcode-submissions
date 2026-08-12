class Solution {
public:
    int maxSum(TreeNode* root, int& sum) {
        if (root == NULL)
            return 0;

        int ls = max(0, maxSum(root->left, sum));
        int rs = max(0, maxSum(root->right, sum));

        sum = max(sum, ls + rs + root->val);

        return root->val + max(ls, rs);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }
};