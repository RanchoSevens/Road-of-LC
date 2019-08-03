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
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> st;
        TreeNode *p;
        vector<TreeNode*> inOrder;
        p=root;
        while(p||!st.empty()){
            if(p!=NULL){
                st.push(p);
                p=p->left;
            }else{
                p=st.top();
                st.pop();
                inOrder.push_back(p);
                p=p->right;
            }
        }
        const int len = inOrder.size();
        for(int i=1;i<len;++i){
            if(inOrder[i]->val<inOrder[i-1]->val){//对i-1使用快排
                int j=len-1;
                int k=i-1;
                while(j>k&&inOrder[j]->val>inOrder[k]->val){
                    j--;
                }
                int temp=inOrder[j]->val;
                inOrder[j]->val=inOrder[k]->val;
                inOrder[k]->val=temp;
                return;
            }
        }
    }
};
/*
1.中序遍历，保留前后两个指针,然后用快排交换一次
*/
