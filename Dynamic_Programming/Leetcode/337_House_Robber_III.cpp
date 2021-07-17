//2021/7/11
class Solution {
public:
    int rob(TreeNode* root) {
        PostOrder(root);
        return dp[root];
    }
private:
    unordered_map<const TreeNode*, int> dp; //dp[i] := maximum amount rooted by i
    //Using PostOrder traversal to build up DP table(bottom-up)
    void PostOrder(const TreeNode *root) {
        int childAmount = 0, grandAmount = 0;
        if (root->left) {
            PostOrder(root->left);
            childAmount+=dp[root->left];
            grandAmount+=((root->left)->left)? dp[(root->left)->left] : 0;
            grandAmount+=((root->left)->right)? dp[(root->left)->right] : 0;
        }
        if (root->right) {
            PostOrder(root->right);
            childAmount+=dp[root->right];
            grandAmount+=((root->right)->left)? dp[(root->right)->left] : 0;
            grandAmount+=((root->right)->right)? dp[(root->right)->right] : 0;
        }
        int best = max(root->val + grandAmount, childAmount);
        dp.insert(make_pair(root, best));
        return;
    }
};