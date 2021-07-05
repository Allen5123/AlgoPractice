//2021/6/27
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> subtree[21]; //all possible FBT that #nodes can generate
        subtree[1].push_back(new TreeNode{});
        for (int i = 3; i <= n; i+=2) { //total number of nodes
            for (int j = 1; j < i-1; j+=2) { //left subtree #nodes from 1, 3,..., i-2
                //gernerate all subtree
                for (int k = 0; k < subtree[j].size(); ++k) { //left subtree
                    for (int l = 0; l < subtree[i-j-1].size(); ++l) { //right subtree
                        TreeNode* temptree = new TreeNode{};
                        temptree->left = subtree[j][k];
                        temptree->right = subtree[i-j-1][l];
                        subtree[i].push_back(temptree);
                    }
                }
            }
        }
        return subtree[n];
    }
};