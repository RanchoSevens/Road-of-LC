class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int left=n,right=n;
        string path;
        dfs(res,path,left,right);
        return res;
    }
    void dfs(vector<string>& res,string path,int left,int right){
        if(!left&&!right){
            res.push_back(path);
        }else{
            if(!left){//必须right
                dfs(res,path+')',left,right-1);
            }else if(left==right){//必须left
                dfs(res,path+'(',left-1,right);
            }else{
                dfs(res,path+')',left,right-1);
                dfs(res,path+'(',left-1,right);
            }
        }
    }
};
/*
1.用一个dfs即可
*/
