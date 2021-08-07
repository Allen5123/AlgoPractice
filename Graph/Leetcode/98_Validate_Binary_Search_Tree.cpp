//2021/8/2
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack <TreeNode*> S;
        TreeNode *cur = root, *pre = nullptr;
        
        //if is BST <=> Inorder-Travelsal ensure to be ascending order
        while (cur || !S.empty()) {
            if (cur) {
                S.push(cur);
                cur = cur->left;
            }
            else {
                cur = S.top();
                S.pop();
                if (pre && pre->val >= cur->val) { return false; }
                pre = cur;
                cur = cur->right;
            }
        }
        
        return true;
    }
};