//2021/8/3
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> S;
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *cur = root, *pre = nullptr;
        
        //Inorder-Travalsal
        while (cur || !S.empty()) {
            if (cur) {
                S.push(cur);
                cur = cur->left;
            }
            else {
                cur = S.top();
                S.pop();
                if (pre && pre->val >= cur->val) {
                    if (!first) {
                        first = pre;
                    }
                    second = cur;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        swap(first->val, second->val);
    }
};