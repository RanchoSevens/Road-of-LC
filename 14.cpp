class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        const int len = strs.size();
        if(len==0) return res;
        int maxl=INT_MAX;
        for(int i=0;i<len;i++){
            int inum = strs[i].length();
            maxl=min(maxl,inum);
        }
        if(maxl==0) return res;
        char a;
        for(int i=0;i<maxl;i++){
            a=strs[0][i];
            int flag=0;
            for(int j=0;j<len;j++){
                if(a!=strs[j][i]){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
            else res = res + a;
        }
        return res;
    }
};

/*
1.从头遍历，遇到不匹配跳出即可
*/
