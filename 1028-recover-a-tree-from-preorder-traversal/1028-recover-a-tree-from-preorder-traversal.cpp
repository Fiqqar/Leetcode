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
    TreeNode* recoverFromPreorder(std::string traversal) {
        std::vector<TreeNode*> stack;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            int val = 0;
            while (i < n && traversal[i] >= '0' && traversal[i] <= '9') {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* node = new TreeNode(val);

            if (depth == stack.size()) {
                if (!stack.empty()) stack.back()->left = node;
            } else {
                while (stack.size() > depth) stack.pop_back();
                stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack[0];
    }
};