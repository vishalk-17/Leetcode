/*2265. Count Nodes Equal to Average of Subtree
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 */

class Solution {
public:
    int ans = 0;

    // returns {sum, count}
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        // Left subtree
        auto left = dfs(root->left);

        // Right subtree
        auto right = dfs(root->right);

        // Current subtree
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Integer division = floor average
        int avg = sum / count;

        if (root->val == avg) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};