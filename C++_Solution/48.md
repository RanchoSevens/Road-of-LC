class Solution {
public:
    void swap(vector<vector<int>>& matrix,int i1,int j1,int i2,int j2){
        int temp = matrix[i1][j1];
        matrix[i1][j1]=matrix[i2][j2];
        matrix[i2][j2]=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix[0].size();
        int n=num;
        num/=2;
        for(int i=0;i<num;++i){
            for(int j=i;j<n-i-1;++j){
                swap(matrix,i,j,j,n-1-i);
                swap(matrix,n-1-j,i,i,j);
                swap(matrix,n-1-i,n-1-j,n-1-j,i);   
            }
        }
    }
};
/*
    1.对于某个位置的点，他需要和另外三个点进行移位，交换三次即可实现
    2.对于整个矩阵，需要分层对每层第一行除最后一个点的所有点进行处理，即可覆盖所有点
*/
