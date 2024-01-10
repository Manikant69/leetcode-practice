/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* createMapping(TreeNode* root, int start,
                            unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
        TreeNode* targetNode = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->val == start) {
                    targetNode = front;
                }

                if (front->left) {
                    q.push(front->left);
                    nodeToParent[front->left] = front;
                }

                if (front->right) {
                    q.push(front->right);
                    nodeToParent[front->right] = front;
                }
            }
        }

        return targetNode;
    }

    int infectTree(TreeNode* root,
                   unordered_map<TreeNode*, TreeNode*> nodeToParent) {
        int ans = 0;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);

        visited[root] = true;

        while (!q.empty()) {
            bool flag = 0;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = 1;
                    visited[front->left] = 1;
                    q.push(front->left);
                }

                if (front->right && !visited[front->right]) {
                    flag = 1;
                    visited[front->right] = 1;
                    q.push(front->right);
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    visited[nodeToParent[front]] = 1;
                    q.push(nodeToParent[front]);
                }
            }

            if (flag) {
                ans++;
            }
        }

        return ans;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        // create node to parent mapping
        unordered_map<TreeNode*, TreeNode*> nodeToParent;

        TreeNode* targetNode = createMapping(root, start, nodeToParent);

        return infectTree(targetNode, nodeToParent);
    }
};
