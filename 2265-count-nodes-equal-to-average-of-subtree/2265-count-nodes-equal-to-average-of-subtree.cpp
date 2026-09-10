class Solution {
private:
    std::pair<int, int> dfs(TreeNode* root, int& countValid) {
        if (!root) return {0, 0};

        auto left = dfs(root->left, countValid);
        auto right = dfs(root->right, countValid);

        int currentSum = root->val + left.first + right.first;
        int currentCount = 1 + left.second + right.second;

        if (currentSum / currentCount == root->val) {
            countValid++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int countValid = 0;
        dfs(root, countValid);
        return countValid;
    }
};