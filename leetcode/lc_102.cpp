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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resTraversal;
        if (!root) {
            return resTraversal;
        }

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            int queueSize = static_cast<int>(bfsQueue.size());
            
            vector<int> curLevel;

            for (int i = 0; i < queueSize; i++) {
                TreeNode* curNode = bfsQueue.front();
                curLevel.push_back(curNode->val);
                bfsQueue.pop();

                if (curNode->left) {
                    bfsQueue.push(curNode->left);
                }
                if (curNode->right) {
                    bfsQueue.push(curNode->right);
                }

            }
            resTraversal.push_back(curLevel);
        }
        return resTraversal;
    }
};
