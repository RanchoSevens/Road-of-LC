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
    bool isValidBST(TreeNode* root) {
        return validate(root,((long)INT_MIN)-1,((long)INT_MAX)+1);
    }
    bool validate(TreeNode* root,long low,long high){
        if(root==NULL) return true;
        if((long)root->val<=low||(long)root->val>=high) return false;
        return validate(root->left,low,(long)root->val)&&validate(root->right,(long)root->val,high);
    }
};
/*
1.为了使low和high包含极端值情况(INT_MAX/INT_MIN)，强转为长整型
*/
