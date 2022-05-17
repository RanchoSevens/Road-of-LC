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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return *generateTreeDFS(1,n);
    }
    vector<TreeNode*> *generateTreeDFS(int start, int end){
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if(start>end){
            subTree->push_back(NULL);
        }else{
            for(int i=start;i<=end;++i){
                vector<TreeNode*> *leftTree = generateTreeDFS(start,i-1);
                vector<TreeNode*> *rightTree = generateTreeDFS(i+1,end);
                for(int j=0;j<leftTree->size();++j){
                    for(int k=0;k<rightTree->size();++k){
                        TreeNode* node = new TreeNode(i);
                        node->left=(*leftTree)[j];
                        node->right=(*rightTree)[k];
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
    
};
/*
1.用递归实现建树，用指针保存树的结点信息
2.递归返回的是一个子树的数组，这样有多少子树就可以遍历建树了
*/
