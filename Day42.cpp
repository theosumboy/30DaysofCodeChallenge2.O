#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<int> res;

        while (!q.empty()) {
            int size = q.size();
            int max_val = INT_MIN;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                max_val = std::max(max_val, node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            res.push_back(max_val);
        }

        return res;
    }
};
