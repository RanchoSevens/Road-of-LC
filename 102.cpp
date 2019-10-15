/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root){
            TreeNode* last;
            vector<int> temp;
            q.push(root);
            last = root;
            while(!q.empty()){
                temp.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                if(q.front()==last){
                    result.push_back(temp);
                    temp.clear();
                    last = q.back();
                }
                q.pop();
            }
        }
        return result;
    }
};
