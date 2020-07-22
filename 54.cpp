class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()!=0)
        {
            int m=matrix.size();
            int n=matrix[0].size();
            int l,r,u,d;
            l=0,r=n,u=0,d=m;
            while(r>l&&d>u){
                int i=l;
                int j=u;
                for(;i<r;++i)    res.push_back(matrix[j][i]);
                --i;
                if(u+1==d) break;
                for(j++;j<d;++j) res.push_back(matrix[j][i]);
                --j;
                if(l+1==r) break;
                for(--i;i>=l;--i) res.push_back(matrix[j][i]);
                ++i;
                for(--j;j>u;--j) res.push_back(matrix[j][i]);
                l++;
                u++;
                d--;
                r--;
            }
        }
        return res;
    }
};
/* 解题思路：
1.按圈循环处理
2.在只剩一行或只剩一列时，在输出行或输出列后跳出
*/
