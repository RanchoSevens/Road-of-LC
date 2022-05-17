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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root){
            vector<TreeNode*> prior,next;
            prior.push_back(root);
            bool flag = true;
            while(!prior.empty()){
                vector<int> temp;
                if(flag){
                    for(int i=prior.size();i>0;--i){
                        if(prior[i-1]->right)   next.push_back(prior[i-1]->right);
                        if(prior[i-1]->left)    next.push_back(prior[i-1]->left);
                        
                    }
                    for(int i=0;i<prior.size();++i){
                        temp.push_back(prior[i]->val);
                    }
                    flag=false;
                }else{
                    for(int i=prior.size();i>0;--i){
                        if(prior[i-1]->left)    next.push_back(prior[i-1]->left);
                        if(prior[i-1]->right)   next.push_back(prior[i-1]->right);
                    }
                    for(int i=0;i<prior.size();++i){
                        temp.push_back(prior[i]->val);
                    }
                    flag=true;
                }
                result.push_back(temp);
                prior=next;
                next.clear();
            }
        }
        return result;
    }
};
