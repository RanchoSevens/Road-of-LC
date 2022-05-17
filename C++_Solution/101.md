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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return judge(root->left,root->right);
    }
    bool judge(TreeNode* left,TreeNode* right){
        if((!left)&&(!right)) return true;
        if((!left&&right)||(!right&&left)||(left&&right&&left->val!=right->val)) return false;
        return judge(left->left,right->right)&&judge(left->right,right->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1,q2;
        q1.push(root->left);  q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1 =  q1.front();
            TreeNode* node2 = q2.front();
            q1.pop(); q2.pop();
            if((!node1&&node2)||(node1&&!node2)){
                return false;
            }
            if(node1){
                if(node1->val!=node2->val) return false;
                q1.push(node1->left);
                q2.push(node2->right);
                q1.push(node1->right);
                q2.push(node2->left);
            }
        }
        return true;
        
    }
    
};
/*
1.递归判断
2.用双队列判断
*/
