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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> level;
        int sz;
        TreeNode* v;
        
        while (!q.empty()) {
            sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                v = q.front();
                q.pop();
                
                if (v) {
                    level.push_back(v->val);
                    if (v->left) q.push(v->left);
                    if (v->right) q.push(v->right);
                }
            }
            
            if (!level.empty()) {
                res.push_back(level);
            }
            level.clear();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};