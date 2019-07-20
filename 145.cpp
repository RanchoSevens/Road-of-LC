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
    vector<int> postorderTraversal(TreeNode* root) {
        stack< TreeNode* > S;
        vector<int> result;
        TreeNode* lastVisited = NULL;
        while(root!=NULL||!S.empty()){
            if(root!=NULL){
                S.push(root);
                root=root->left;
            }else{
                root = S.top();
                if(root->right!=NULL&&root->right!=lastVisited){
                    root=root->right;
                }else{
                    result.push_back(root->val);
                    lastVisited=root;
                    S.pop();
                    root=NULL;
                }
            }
        }
        return result;
    }
};
/*
1.当前结点无右子树-->访问
2.当前结点有右子树&&未访问过-->访问
3.当前结点有右子树&&未访问-->向右走
*/
